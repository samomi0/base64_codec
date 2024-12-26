#include "base64.h"
#include "gtest/gtest.h"

TEST(BasicTest, EncodeTest) {
  Base64::Base64Codec b64_codec;
  std::string test_str = "This is an example.";
  std::string base64_str;
  b64_codec.encode(std::vector<char>(test_str.begin(), test_str.end()),
                   base64_str);
  EXPECT_EQ(base64_str, "VGhpcyBpcyBhbiBleGFtcGxlLg==");
}

TEST(BasicTest, DecodeTest) {
  Base64::Base64Codec b64_codec;
  std::string test_str = "VGhpcyBpcyBhbiBleGFtcGxlLg==";
  std::vector<char> output;
  b64_codec.decode(test_str, output);
  std::string base64_str(output.begin(), output.end());
  EXPECT_EQ(base64_str, "This is an example.");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}