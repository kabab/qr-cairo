#include "../src/qr_cairo.h"

int main() {
  QrCairo qr("Amine KAB", QrCairo::L);
  qr.set_box_size(20);
  qr.set_fill_color("#ff0000");
  // qr.set_back_color("#ff0f0f");
  qr.save("test.png", "svg");
  return 0;
}
