#include "Hourglass.h"
#include "YouSquared.h"
#include <stdio.h>

#define CHAR_HEIGHT 10
#define CHAR_WIDTH 10

unsigned char reverse_bits3(unsigned char b) {
  return (b * 0x0202020202ULL & 0x010884422010ULL) % 0x3ff;
}

// a MVP script that converts the zx-origins fonts pixel order to be
// left-to-right as expected by the picoTracker firmware

int main(int argc, char const *argv[]) {
  printf("converting font...\n");
  printf("{\n{");
  for (int i = 1; i <= (96 * 8); i++) {
    // const uint8_t pixel_data = FONT_YOU_SQUARED_BITMAP[i-1];
    const uint8_t pixel_data = FONT_HOURGLASS_BITMAP[i - 1];
    uint8_t pix = reverse_bits3(pixel_data);
    printf("0x%2.2X,", pix);
    if (i % 8 == 0 && i != 0) {
      printf("},\n{");
    }
  }

  printf("};\n");
  return 0;
}
