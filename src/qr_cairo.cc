#include <string.h>
#include <stdlib.h>
#include "qr_cairo.h"

QrCairo::QrCairo (const char* data, EC_LEVEL ec) :
  fill(0, 0, 0, 1), back(1, 1, 1, 0) {

  this->data = strdup(data);
  this->ec = ec;
  this->box_size = 4;

  this->qr_code = 0;
  this->qr_image = 0;
}

void QrCairo::set_fill_color (const Color& f) {
  this->fill = f;
}

void QrCairo::set_back_color (const Color& b) {
  this->back = b;
}

void QrCairo::generate () {
  qr_code = QRcode_encodeString (data, 0, (QRecLevel) ec, QR_MODE_KANJI, 1);
  
  qr_image = new QrImage(qr_code->width, box_size, back, fill);

  unsigned char *p = qr_code->data;

  for(int i = 0; i < qr_code->width; i++) {
    for(int j = 0; j < qr_code->width; j++) {
      if (*p & 1) {
        qr_image->draw(j, i);
      }
      p++;
    }
  }
}

void QrCairo::set_box_size (int size) {
  this->box_size = size;
}

void QrCairo::save (const char* filename, const char* filetype) {
  QrImage::Type t = QrImage::PNG;
  if (strcmp(filetype, "png") == 0) {
    t = QrImage::PNG;
  } else if (strcmp(filetype, "svg") == 0) {
    t = QrImage::SVG;
  }
  
  this->generate();
  this->qr_image->save(filename, t);
}

