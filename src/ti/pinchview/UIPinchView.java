package ti.pinchview;

import java.lang.ref.SoftReference;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.view.TiUIView;
import org.json.JSONException;
import org.json.JSONObject;

import android.content.Context;
import android.content.pm.PackageManager;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Display;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.ScaleGestureDetector.SimpleOnScaleGestureListener;
import android.view.View;

public class UIPinchView extends TiUIView {
	public PinchView tiPinchView;
	private float maxZoom = 5.f;
	private float minZoom = 0.1f;
	private float startX;
	private float startY;
	private int CLICK_ACTION_THRESHOLD = 200;
	private float DENSITY = 1;
	private SoftReference<Display> softDisplay;
	private DisplayMetrics dm;

	public UIPinchView(TiViewProxy proxy) {
		super(proxy);

		setNativeView(tiPinchView = new PinchView(proxy.getActivity()));
		dm = new DisplayMetrics();
		synchronized (dm) {
			getDisplay().getMetrics(dm);
			DENSITY = dm.density;
		}
	}

	@Override
	public void processProperties(KrollDict d) {
		super.processProperties(d);
		if (d.containsKeyAndNotNull("maxZoomValue"))
			maxZoom = d.getDouble("maxZoomValue").floatValue();
		if (d.containsKeyAndNotNull("minZoomValue"))
			minZoom = d.getDouble("minZoomValue").floatValue();

		Log.d("UIPinchView", minZoom + " " + maxZoom);
	}

	public void setMaxZoomValue(float maxZoom) {
		this.maxZoom = maxZoom;
	}

	public void setMinZoomValue(float minZoom) {
		this.minZoom = minZoom;
	}

	public class PinchView extends View {
		private static final int INVALID_POINTER_ID = -1;
		private int activePointerId;
		private ScaleGestureDetector pinchDetector;
		private float scaleFactor = 1.f;
		private float lastX, lastY;

		public PinchView(Context c) {
			super(c);
			if (c.getPackageManager().hasSystemFeature(
					PackageManager.FEATURE_TOUCHSCREEN_MULTITOUCH))
				pinchDetector = new ScaleGestureDetector(c, new ScaleListener());
		}

		@Override
		public boolean onTouchEvent(MotionEvent e) {
			if (pinchDetector != null)
				pinchDetector.onTouchEvent(e);

			final int action = e.getAction();

			JSONObject json = new JSONObject();
			KrollDict eventData = null;

			switch (action & MotionEvent.ACTION_MASK) {
			case MotionEvent.ACTION_DOWN: {
				startX = e.getX();
				startY = e.getY();
				final float x = e.getX();
				final float y = e.getY();
				try {
					json.put("x", x);
					json.put("y", y);
					eventData = new KrollDict(json);
				} catch (JSONException exc) {
					Log.e("PinchView:onTouchEvent", exc.getMessage());
					return false;
				}
				proxy.fireEvent("multiStart", eventData);
				activePointerId = e.getPointerId(0);
				lastX = x;
				lastY = y;
				break;
			}
			case MotionEvent.ACTION_MOVE: {
				final int pointerIndex = e.findPointerIndex(activePointerId);
				final float x = e.getX(pointerIndex);
				final float y = e.getY(pointerIndex);
				if (!pinchDetector.isInProgress()) {
					try {
						json.put("x", x - lastX);
						json.put("y", y - lastY);
						eventData = new KrollDict(json);
					} catch (JSONException exc) {
						Log.e("PinchView:onTouchEvent", exc.getMessage());
						return false;
					}
					proxy.fireEvent("multiMove", eventData);
				}
				lastX = x;
				lastY = y;
				break;
			}
			case MotionEvent.ACTION_UP: {
				float endX = e.getX();
				float endY = e.getY();
				if (isAClick(startX, endX, startY, endY)) {
					KrollDict dict = new KrollDict();
					dict.put("x", endX / DENSITY);
					dict.put("y", endY / DENSITY);
					if (proxy.hasListeners("click"))
						proxy.fireEvent("click", dict);
				}
				activePointerId = INVALID_POINTER_ID;
				proxy.fireEvent("multiEnd", eventData);
				break;
			}
			case MotionEvent.ACTION_POINTER_UP: {
				final int pointerIndex = (e.getAction() & MotionEvent.ACTION_POINTER_INDEX_MASK) >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
				final int pointerId = e.getPointerId(pointerIndex);
				if (pointerId == activePointerId) {
					final int newPointerIndex = pointerIndex == 0 ? 1 : 0;
					activePointerId = e.getPointerId(newPointerIndex);
					lastX = e.getX(newPointerIndex);
					lastY = e.getY(newPointerIndex);
				}
				break;
			}
			}

			return true;
		}

		private boolean isAClick(float startX, float endX, float startY,
				float endY) {
			float differenceX = Math.abs(startX - endX);
			float differenceY = Math.abs(startY - endY);
			return !(differenceX > CLICK_ACTION_THRESHOLD/* =5 */|| differenceY > CLICK_ACTION_THRESHOLD);
		}

		private class ScaleListener extends SimpleOnScaleGestureListener {
			@Override
			public boolean onScale(ScaleGestureDetector detector) {
				scaleFactor *= detector.getScaleFactor();

				scaleFactor = Math.max(minZoom, Math.min(scaleFactor, maxZoom));
				invalidate();

				JSONObject json = new JSONObject();
				KrollDict eventData = null;
				try {
					json.put("scale", scaleFactor);
					eventData = new KrollDict(json);
				} catch (JSONException e) {
					Log.e("PinchView:onScale", e.getMessage());
				}
				if (proxy.hasListeners("pinch"))
				proxy.fireEvent("pinch", eventData);

				return true;
			}

			@Override
			public void onScaleEnd(ScaleGestureDetector detector) {
				KrollDict event = new KrollDict();
				if (proxy.hasListeners("pinchEnd"))
					proxy.fireEvent("pinchEnd", event);
			}
		}
	}

	private Display getDisplay() {
		if (softDisplay == null || softDisplay.get() == null) {
			// we only need the window manager so it doesn't matter if the root
			// or current activity is used
			// for accessing it
			softDisplay = new SoftReference<Display>(TiApplication
					.getAppRootOrCurrentActivity().getWindowManager()
					.getDefaultDisplay());
		}
		return softDisplay.get();
	}
}
