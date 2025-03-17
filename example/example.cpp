#include <string>
#include <vector>
#include <memory>

#include "base64.h"

int main() {
  auto b64codec = std::make_shared<Base64::Base64Codec>();
  std::string test_str = "This is an example.";
  std::string base64_str;
  std::string decode_base64_str;

  try {
    b64codec->Base64Encode(std::vector<char>(test_str.begin(), test_str.end()), base64_str);

    std::vector<char> output;
    b64codec->Base64Decode(base64_str, output);
    decode_base64_str = std::string(output.begin(), output.end());
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "Base64:[" << base64_str << "]" << std::endl;
  std::cout << "decode Base64:[" << decode_base64_str << "]" << std::endl;

  return 0;
}