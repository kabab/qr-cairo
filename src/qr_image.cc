#include <cairo-svg.h>
#include "qr_image.h"

QrImage::QrImage (int size, int box_size, Color back, Color fill) {
  double alpha;
  
  this->size = size;
  this->box_size = box_size;
  
  int width = size * box_size + box_size * 4 * 2;

  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, width);
  cr = cairo_create (surface);
  
  alpha = back.alpha() >= 0.0 ? back.alpha() : 1;
  cairo_set_source_rgba(cr, back.red(), back.green(), back.blue(), alpha);
  cairo_paint(cr);

  alpha = fill.alpha() >= 0.0 ? fill.alpha() : 1;  
  cairo_set_source_rgba(cr, fill.red(), fill.green(), fill.blue(), alpha);
}

void QrImage::set_fill_color (const Color& c) {
  double a = c.alpha() >= 0.0 ? c.alpha() : 1;
  cairo_set_source_rgba(cr, c.red(), c.green(), c.blue(), a);
}

void QrImage::draw (int x, int y) {

  double pos_x = (double)x * box_size + box_size * 4;
  double pos_y = (double)y * box_size + box_size * 4;

  cairo_rectangle(cr, pos_x, pos_y, box_size, box_size);
  cairo_fill(cr);
}

void QrImage::save(const char *filename, QrImage::Type t) {
  
  switch (t) {
  case PNG:
    cairo_surface_write_to_png(surface, filename);
    break;
  case SVG: {
    int width = size * box_size + 4 * 2 * box_size;
    cairo_surface_t *svg_surface = cairo_svg_surface_create(filename, width, width);
    cairo_set_source_surface (cr, svg_surface, 0, 0);
    cairo_save (cr);
    cairo_rectangle (cr, 0, 0, width, width);
    cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
    cairo_fill (cr);
    cairo_restore (cr);
    cairo_surface_destroy (svg_surface);
    break;
  }
  }
}

QrImage::~QrImage() {
  cairo_destroy(cr);
  cairo_surface_destroy(surface);
}
