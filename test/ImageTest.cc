#include <stdio.h>
#include <stdlib.h>
#include "../src/qr_image.h"
#include <qrencode.h>

int main() {
  QRcode *code;  

  code = QRcode_encodeString("Version 2", 2, QR_ECLEVEL_L, QR_MODE_KANJI, 1);
  
  QrImage img(code->width, 10);
  unsigned char *p = code->data;

  for(int i = 0; i < code->width; i++) {
    for(int j = 0; j < code->width; j++) {
      if (*p & 1) {
        img.draw(j, i);
      }
      p++;
    }
  }

  img.save("test.png", QrImage::SVG);
  return 0;
}
