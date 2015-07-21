#include "Image.h"

Image::Image(int size, Color back, int box_size) : 
  back(0, 0, 0, 1), fill(1, 1, 1, 0) {
 
  this->size = size;
  this->box_size = box_size;
  int width = size * box_size;

  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32,
                                        width, width);
  cr = cairo_create (surface);
  
  cairo_set_source_rgba(cr, 0, 0, 0, 1);
  cairo_set_line_width(cr, 1);
}

void Image::set_fill_color(const Color& c) {
  // fill = c;
  // cairo_set_source_rgba();
}


void Image::draw(int x, int y, bool v) {
  
  double pos_x = (double)x * box_size;
  double pos_y = (double)y * box_size;

  cairo_rectangle(cr, pos_x, pos_y, box_size, box_size);
  cairo_fill(cr);
}

void Image::save(char *filename) {
  cairo_surface_write_to_png(surface, filename);
}

Image::~Image() {
  cairo_destroy(cr);
  cairo_surface_destroy(surface);
}
