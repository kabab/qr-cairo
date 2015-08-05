#include <stdlib.h>
#include <node.h>
#include <v8.h>
#include "qr_cairo.h"

using namespace v8;

void create_qr(const char* text, const char* filename) {
  QrCairo qr(text, QrCairo::L);
  qr.save(filename, "png");
}

char *get(v8::Local<v8::Value> value) {
  v8::String::Utf8Value string(value);
  char *str = (char *) malloc(string.length() + 1);
  strcpy(str, *string);
  return str;
}


void Save(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsString() || !args[1]->IsString()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }


  char *text = get(args[0]);
  char *filename = get(args[1]);

  create_qr(text, filename);
  delete text;
  delete filename;
}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "save", Save);
}

NODE_MODULE(addon, Init)
