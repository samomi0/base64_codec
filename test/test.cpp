#include "base64.h"
#include "gtest/gtest.h"

TEST(BasicTest, EncodeTest) {
  auto b64codec = std::make_shared<Base64::Base64Codec>();
  std::string test_str = "This is an example.";
  std::string base64_str;
  b64codec->Base64Encode(std::vector<char>(test_str.begin(), test_str.end()), base64_str);
  EXPECT_EQ(base64_str, "VGhpcyBpcyBhbiBleGFtcGxlLg==");
}

TEST(BasicTest, DecodeTest) {
  auto b64codec = std::make_shared<Base64::Base64Codec>();
  std::string test_str = "VGhpcyBpcyBhbiBleGFtcGxlLg==";
  std::vector<char> output;
  b64codec->Base64Decode(test_str, output);
  std::string base64_str(output.begin(), output.end());
  EXPECT_EQ(base64_str, "This is an example.");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}