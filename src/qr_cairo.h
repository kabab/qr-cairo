#ifndef QR_CAIRO_H
#define QR_CAIRO_H

#include <qrencode.h>
#include "color.h"
#include "qr_image.h"

class QrCairo {
public:
  enum EC_LEVEL {L, Q, H, M};
  QrCairo(const char *, EC_LEVEL)
  void set_fill_color(const Color&);
  void set_back_color(const Color&);
  void save(const char*, const char*);
  void set_box_size(int size);
private:
  void generate();
  
  QRcode *qr_code;
  QrImage *qr_image;
  Color fill, back;
  char *data;
  EC_LEVEL ec;
  int box_size;
}

#endif
