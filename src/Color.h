#ifndef COLOR_H
#define COLOR_H

#include <cstring>

class Color {

 public:
  Color(double r, double g, double b, double a = -1);
  Color(char *color);
  static bool is_valid_color(char *color);
  void setAlpha(double a);
  double red();
  double blue();
  double green();
  double alpha();
 private:
  double r, g, b, a;
};

#endif 
