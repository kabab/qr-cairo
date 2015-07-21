#ifndef IMAGE_H
#define IMAGE_H

#include <cairo.h>
#include "Color.h"

class Image {
 public:
  Image(int size,  Color back, int box_size = 4);
  void set_fill_color(const Color&);
  void draw(int x, int y, bool v);
  void save(char *filename);
  ~Image();
 private:
  Color fill, back;
  int size, box_size;
  cairo_t *cr;
  cairo_surface_t *surface;
};


#endif
