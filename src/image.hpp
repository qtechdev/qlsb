#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__
#include <string>
#include <vector>

#include <cstdint>

namespace qimg {
  struct pixel {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    pixel &operator|=(const pixel &rhs);
    pixel &operator+=(const pixel &rhs);
    pixel &operator*=(const float &rhs);
  };

  inline pixel operator|(pixel lhs, const pixel &rhs) { return lhs |= rhs; }
  inline pixel operator+(pixel lhs, const pixel &rhs) { return lhs += rhs; }
  inline pixel operator*(pixel lhs, const float rhs) { return lhs *= rhs; }

  struct image {
    int w;
    int h;
    std::vector<pixel> data;

    image &operator|=(const image &rhs);
  };

  inline image operator|(image lhs, const image &rhs) { return lhs |= rhs; }

  image load_image(const std::string &p);
  bool save_image_png(const image &img, const std::string &path);
  image copy_image(const image &img);
}

#endif // __IMAGE_HPP__
