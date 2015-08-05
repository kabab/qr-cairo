#include <stdlib.h>
#include <node.h>
#include <v8.h>
#include "qr_cairo.h"

using namespace v8;

typedef struct {
  QrCairo::EC_LEVEL ecl; // Error correction level
  int box_size;
  char *back_color;
  char *fill_color;
} option_t;


void create_qr(const char* text, const char* filename, option_t *options = 0) {
  QrCairo *qr;

  if(options != 0) {
    qr = new QrCairo(text, options->ecl);

    if(options->box_size > 0) {
      qr->set_box_size(options->box_size);
    }
    
    if(options->back_color != 0) {
      qr->set_back_color(options->back_color);
      delete options->back_color;
    }
    
    if(options->fill_color != 0) {
      qr->set_fill_color(options->fill_color);
      delete options->fill_color;
    }
  } else {
    qr = new QrCairo(text, QrCairo::L);
  }

  qr->save(filename, "png");
  delete qr;
}

char *get_cstr(Local<Value> value) {
  String::Utf8Value string(value);
  char *str = (char *) malloc(string.length() + 1);
  strcpy(str, *string);
  return str;
}


QrCairo::EC_LEVEL CStrToECLEVEL(const char *ecl) {

  switch(ecl[0]) {
  case 'L':
  case 'l':
    return QrCairo::L;
  case 'Q':
  case 'q':
    return QrCairo::Q;
  case 'H':
  case 'h':
    return QrCairo::H;
  case 'M':
  case 'm':
    return QrCairo::M;
  default:
    return QrCairo::L;
  }
}

option_t* ObjectToOptions(const Local<Object>& obj) {
  option_t* options = new option_t;
  Isolate* isolate = Isolate::GetCurrent();

  if(obj->Has(String::NewFromUtf8(isolate, "box_size"))) {
    Local<Value> tmp = obj->Get(String::NewFromUtf8(isolate, "box_size"));
    options->box_size = tmp->IntegerValue(); 
  } else {
    options->box_size = -1;
  }

  if(obj->Has(String::NewFromUtf8(isolate, "back_color"))) {
    Local<Value> tmp = obj->Get(String::NewFromUtf8(isolate, "back_color"));
    options->back_color = get_cstr(tmp);
  } else {
    options->back_color = 0;
  }

  if(obj->Has(String::NewFromUtf8(isolate, "fill_color"))) {
    Local<Value> tmp = obj->Get(String::NewFromUtf8(isolate, "fill_color"));
    options->fill_color = get_cstr(tmp);
  } else {
    options->fill_color = 0;
  }

  if(obj->Has(String::NewFromUtf8(isolate, "ec_level"))) {
    Local<Value> tmp = obj->Get(String::NewFromUtf8(isolate, "ec_level"));
    char *ecl = get_cstr(tmp);
    options->ecl = CStrToECLEVEL(ecl),
    delete ecl;
  } else {
    options->ecl = QrCairo::L;
  }

  return options;
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

  if(args.Length() == 3 && !args[2]->IsObject()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Thrid argument must be an object")));
    return;
  }
  
  char *text = get_cstr(args[0]);
  char *filename = get_cstr(args[1]);

  option_t *options = 0;

  if(args.Length() == 3 && args[2]->IsObject()) {
    Local<Object> obj = args[2]->ToObject();
    options = ObjectToOptions(obj);  
  }
  
  create_qr(text, filename, options);
  
  delete options;
  delete text;
  delete filename;
}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "save", Save);
}

NODE_MODULE(addon, Init)
