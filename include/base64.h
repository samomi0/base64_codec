#pragma once

#include "base64_impl.h"
namespace Base64 {
class Base64Codec : Base64CodecImpl {
 public:
  Base64Codec() = default;
  ~Base64Codec() = default;

  int Base64Encode(const std::vector<char> &src, std::string &dst) {
    return Base64CodecImpl::encode(src, dst);
  }

  int Base64Decode(const std::string &src, std::vector<char> &dst) {
    return Base64CodecImpl::decode(src, dst);
  }
};
}   // namespace Base64