#include "../utf8.h"
using namespace stakk;

int main() {
  string a = "あ";
  assert( utf8_len('a') == 1 );
  assert( utf8_len(a[0]) == 3 );

  string input = "これはテストです。";
  size_t length = 9;
  assert(utf8_len(input.c_str(), input.length()) == length);
  assert(utf8_char(input.c_str()) == 3);

  vector<string> splited = utf8_split(input);
  assert(splited.size() == length);
  assert(splited[3] == "テ");
  assert(utf8_substring(input, 3, 3) == "テスト");

  return 0;
}
