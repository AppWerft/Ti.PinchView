// This is a test harness for your module
// You should do something interesting in this harness 
// to test out the module and to provide instructions 
// to users on how to use it by example.

var startX, startY, startLeft, startTop;

// open a single window
var window = Ti.UI.createWindow({
	backgroundColor:'black'
});


// TODO: write your module tests here
var multitouch = require('ti.pinchview');

var pinchView = multitouch.createPinchView({
	top:0,
	left:0,
	width:Ti.Platform.displayCaps.platformWidth,
	height:Ti.Platform.displayCaps.platformHeight,
	backgroundColor:'transparent',
	minZoomValue:0.5,
	maxZoomValue:1
});

var view = Ti.UI.createView({
	top:0,
	left:0,
	width:Ti.Platform.displayCaps.platformWidth / 2,
	height:Ti.Platform.displayCaps.platformHeight / 2,
	backgroundColor:'white',
	touchEnabled:false
});
window.add(view);
window.add(pinchView);
window.open();

pinchView.addEventListener('pinch',function(e) {
	var oldWidth = view.width;
	var oldHeight = view.height;
	view.width = Ti.Platform.displayCaps.platformWidth / 2 * e.scale;
	view.height = Ti.Platform.displayCaps.platformHeight / 2 * e.scale;
	var deltaWidth = view.width - oldWidth;
	var deltaHeight = view.height - oldHeight;
	view.left -= deltaWidth / 2;
	view.top -= deltaHeight / 2;
});

pinchView.addEventListener('multiStart', function(e) {
	startX = view.left;
	startY = view.top;
});

pinchView.addEventListener('multiMove',function(e) {
	view.left += e.x;
	view.top += e.y;
	startLeft = view.left;
	startTop = view.top;
});

pinchView.addEventListener('doubletap', function(e) {
	Ti.API.debug("DOUBLE TAP");
});

