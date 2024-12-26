#include "base64.h"

#include <limits.h>

#include <sstream>

namespace Base64 {

int Base64Codec::encode(const std::vector<char> &src, std::string &dst) {
  std::stringstream ss;
  unsigned i_bits = 0;
  int i_shift = 0;
  int bytes_remaining = src.size();
  unsigned char *p = (unsigned char *)src.data();

  if (src.size() >= UINT_MAX / 4) {
    return -1;
  }

  while (bytes_remaining) {
    i_bits = (i_bits << 8) + *p++;
    bytes_remaining--;
    i_shift += 8;

    do {
      ss.put(base64_chars[(i_bits << 6 >> i_shift) & 0x3f]);
      i_shift -= 6;
    } while (i_shift > 6 || (bytes_remaining == 0 && i_shift > 0));
  }

  while (ss.tellp() & 3) {
    ss.put('=');
  }

  dst = ss.str();

  return 0;
}

int Base64Codec::decode(const std::string &src, std::vector<char> &dst) {
  int val = 0;

  for (size_t i = 0; i < src.size(); ++i) {
    unsigned char c = src[i];

    if (c == '=') {
      break;
    }

    if (c <= ' ') {
      continue;
    }

    unsigned int index = c - 43;
    if (index >= (sizeof(base64_table) / sizeof(base64_table[0])) ||
        base64_table[index] == 0xff) {
      throw std::invalid_argument("Invalid character in Base64 string");
    }

    val = (val << 6) + base64_table[index];
    if (i & 3) {
      dst.push_back(val >> (6 - 2 * (i & 3)));
    }
  }

  return 0;
}

}  // namespace B64