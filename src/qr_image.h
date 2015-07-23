#ifndef QR_IMAGE_H
#define QR_IMAGE_H

#include <cairo.h>
#include "color.h"

class QrImage {
 public:
  enum Type { PNG, SVG };

  QrImage(int size, int box_size = 4, Color back = Color(1, 1, 1, 0),
          Color fill = Color(0, 0, 0, 1));
  void set_fill_color(const Color&);
  void draw(int x, int y);
  void save(const char *filename, QrImage::Type t);
  ~QrImage();
 private:
  int size, box_size;
  cairo_t *cr;
  cairo_surface_t *surface;
};


#endif
