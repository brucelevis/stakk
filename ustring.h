#ifndef USTRING_H
#define USTRING_H

#include "common.h"

namespace stakk {

typedef basic_string<uint16_t> ustring;
size_t get_len(char c) {
  const uint8_t len_table[256] = {
    1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,
    3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3, 4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4
  };
  return (size_t)len_table[(uint8_t)c];
}

class Ustring {
 private:
  vector<string> u2s;
  map<string, uint16_t> s2u;
 public:
  Ustring() {
    u2s.push_back("NULL");
  }
  ustring decode(string input) {
    ustring result;
    for (size_t i = 0; i < input.length(); i+= get_len(input[i])) {
      string c = input.substr(i, get_len(input[i]));
      uint16_t id = s2u[c];
      if (id == 0) {
        u2s.push_back(c);
        id = u2s.size() - 1;
        s2u[c] = id;
      }
      result.push_back(id);
    }
    return result;
  }
  string encode(ustring input) {
    string result;
    for (size_t i = 0; i < input.length(); i++) {
      result += u2s[input[i]];
    }
    return result;
  }
  size_t size() {
    if (u2s.size()-1 == s2u.size()) {
      return s2u.size();
    }
    return 0;
  }
};
}
#endif
