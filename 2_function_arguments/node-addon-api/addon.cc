#include <napi.h>

Napi::Value createExternalBuffer(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsBuffer()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!info[1].IsNumber())
  {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  auto buf = info[0].As<Napi::Buffer<char>>();
  auto length = info[1].As<Napi::Number>().Int32Value();

  return Napi::Buffer<char>::New(env, buf.Data(), length);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "createExternalBuffer"), Napi::Function::New(env, createExternalBuffer));
  return exports;
}

NODE_API_MODULE(addon, Init)
