#ifndef COLOR_H
#define COLOR_H

#include <cstring>

class Color {

 public:
  Color(double r, double g, double b, double a = -1);
  Color(const char *color);
  Color(const Color& color);
  static bool is_valid_color(const char *color);
  void setAlpha(double a);
  double red() const;
  double blue() const;
  double green() const;
  double alpha() const;
 private:
  double r, g, b, a;
};

#endif 
