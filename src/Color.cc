#include "Color.h"
#include <cassert>
#include <stdlib.h>

#include <iostream>

#define is_hex(x) ((x >= 'A' && x <= 'F') ||    \
                   (x >= 'a' && x <= 'f') ||    \
                   (x >= '0' && x <= '9'))

Color::Color(double r, double g, double b, double a) {
  assert(r >= 0 && r <= 1 && g >= 0 && g <= 1 &&
         b >= 0 && b <= 1 && ((a >= 0 && a <= 1) || a == -1));
  
  this->r = r, this->g = g, this-> b = b, this->a = a;
}


bool Color::is_valid_color(char *color) {
  int len = std::strlen(color);

  if(len != 4 && len != 7 && color[0] != '#') {
    return false;
  }

  for(int i = 1; i < len; i++) {
    char c = color[i];
    if(! is_hex(c)) {
      return false;
    }
  }

  return true;
}

Color::Color(char *color) {
  assert(Color::is_valid_color(color)); 

  int len = std::strlen(color);
  int hexcolor = strtol(&color[1], NULL, 16);
  b = (hexcolor & 0xff) / 255.0;
  hexcolor >>= 8;
  g = (hexcolor & 0xff) / 255.0;
  hexcolor >>= 8;
  r = (hexcolor & 0xff) / 255.0;
}

void Color::setAlpha(double a) {
  assert( a >= 0 && a <= 1);
  this-> a = a;
}

double Color::red() {
  return this->r;
}


double Color::blue() {
  return this->b;
}

double Color::green() {
  return this->g;
}

double Color::alpha() {
  return this->a;
}
