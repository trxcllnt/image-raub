#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include <FreeImage.h>

#include <addon-tools.hpp>


class Image : public Napi::ObjectWrap<Image> {
	
public:
	
	// Public Napi init
	static void init(Napi::Env env, Napi::Object exports);
	static bool isImage(Napi::Object obj);
	
	explicit Image(const Napi::CallbackInfo& info);
	~Image();
	
	// Destroy an instance from C++ land
	void _destroy();
	
protected:
	
	JS_GETTER(isDestroyedGetter);
	JS_GETTER(widthGetter);
	JS_GETTER(heightGetter);
	
	JS_METHOD(destroy);
	
	JS_METHOD(_load);
	JS_METHOD(_unload);
	JS_METHOD(save);
	
	JS_METHOD(drawImage);
	
	void emit(const Napi::CallbackInfo& info, const char* name);
	
 private:
	
	static Napi::FunctionReference _constructor;
	
	bool _isDestroyed;
	
	FIBITMAP *_bitmap;
	
};


#endif // _IMAGE_HPP_
