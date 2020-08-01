#include "image.hpp"
#include "transform.hpp"

void tx::grey(qimg::image &img) {
  for (int y = 0; y < img.h; ++y) {
    for (int x = 0; x < img.w; ++x) {
      int pixel_index = ((y * img.w) + x) * img.ch;

      float r = img.data[pixel_index];
      float g = img.data[pixel_index + 1];
      float b = img.data[pixel_index + 2];

      unsigned char grey = (r * 0.3) + (g * 0.59) + (b * 0.11);

      img.data[pixel_index] = grey;
      img.data[pixel_index + 1] = grey;
      img.data[pixel_index + 2] = grey;
    }
  }
}