/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2017 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.pinchview.PinchViewProxy.h"

#include "AndroidUtil.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "TypeConverter.h"
#include "V8Util.h"


#include "org.appcelerator.titanium.proxy.TiViewProxy.h"

#define TAG "PinchViewProxy"

using namespace v8;

namespace ti {
namespace pinchview {
	namespace pinch {


Persistent<FunctionTemplate> PinchViewProxy::proxyTemplate;
jclass PinchViewProxy::javaClass = NULL;

PinchViewProxy::PinchViewProxy() : titanium::Proxy()
{
}

void PinchViewProxy::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);

	v8::TryCatch tryCatch(isolate);
	Local<Function> constructor;
	MaybeLocal<Function> maybeConstructor = pt->GetFunction(context);
	if (!maybeConstructor.ToLocal(&constructor)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}

	Local<String> nameSymbol = NEW_SYMBOL(isolate, "PinchView"); // use symbol over string for efficiency
	exports->Set(nameSymbol, constructor);
}

void PinchViewProxy::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::TiViewProxy::dispose(isolate);
}

Local<FunctionTemplate> PinchViewProxy::getProxyTemplate(Isolate* isolate)
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "PinchViewProxy::getProxyTemplate()");

	javaClass = titanium::JNIUtil::findClass("ti/pinchview/PinchViewProxy");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "PinchView");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(isolate,
		titanium::TiViewProxy::getProxyTemplate(isolate)
, javaClass, nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate),
		FunctionTemplate::New(isolate, titanium::Proxy::inherit<PinchViewProxy>));

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "setMaxZoomValue", PinchViewProxy::setMaxZoomValue);
	titanium::SetProtoMethod(isolate, t, "setMinZoomValue", PinchViewProxy::setMinZoomValue);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "maxZoomValue"),
			titanium::Proxy::getProperty,
			PinchViewProxy::setter_maxZoomValue,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "minZoomValue"),
			titanium::Proxy::getProperty,
			PinchViewProxy::setter_minZoomValue,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

// Methods --------------------------------------------------------------------
void PinchViewProxy::setMaxZoomValue(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setMaxZoomValue()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PinchViewProxy::javaClass, "setMaxZoomValue", "(F)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setMaxZoomValue' with signature '(F)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setMaxZoomValue: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	

		if ((titanium::V8Util::isNaN(isolate, args[0]) && !args[0]->IsUndefined()) || args[0]->ToString(isolate)->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber(isolate);
		jArguments[0].f =
			titanium::TypeConverter::jsNumberToJavaFloat(
				env, arg_0);
	} else {
		jArguments[0].f = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void PinchViewProxy::setMinZoomValue(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setMinZoomValue()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PinchViewProxy::javaClass, "setMinZoomValue", "(F)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setMinZoomValue' with signature '(F)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setMinZoomValue: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	

		if ((titanium::V8Util::isNaN(isolate, args[0]) && !args[0]->IsUndefined()) || args[0]->ToString(isolate)->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		}
	if (!args[0]->IsNull()) {
		Local<Number> arg_0 = args[0]->ToNumber(isolate);
		jArguments[0].f =
			titanium::TypeConverter::jsNumberToJavaFloat(
				env, arg_0);
	} else {
		jArguments[0].f = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}

// Dynamic property accessors -------------------------------------------------


void PinchViewProxy::setter_maxZoomValue(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, maxZoomValue wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PinchViewProxy::javaClass, "setMaxZoomValue", "(F)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setMaxZoomValue' with signature '(F)V'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(args.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	

		if ((titanium::V8Util::isNaN(isolate, value) && !value->IsUndefined()) || value->ToString(isolate)->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		Local<Number> arg_0 = value->ToNumber(isolate);
		jArguments[0].f =
			titanium::TypeConverter::jsNumberToJavaFloat(
				env, arg_0);
	} else {
		jArguments[0].f = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}



void PinchViewProxy::setter_minZoomValue(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, minZoomValue wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(PinchViewProxy::javaClass, "setMinZoomValue", "(F)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setMinZoomValue' with signature '(F)V'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(args.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	

		if ((titanium::V8Util::isNaN(isolate, value) && !value->IsUndefined()) || value->ToString(isolate)->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		Local<Number> arg_0 = value->ToNumber(isolate);
		jArguments[0].f =
			titanium::TypeConverter::jsNumberToJavaFloat(
				env, arg_0);
	} else {
		jArguments[0].f = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}



	} // namespace pinch
} // pinchview
} // ti
