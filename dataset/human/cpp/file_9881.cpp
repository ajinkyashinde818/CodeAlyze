#include <bits/stdc++.h>

uint64_t calc(uint64_t x) {
  uint64_t v = 1;
  for (uint64_t i = 1; i < x; i++) {
    v *= 2;
  }
  return v % 1000000007;
}

int main() {
  uint64_t n;
  std::string s;
  std::cin >> n;
  std::cin >> s;

  std::vector<int> alpha(26, 0);
  for (const auto c : s) {
    alpha[c - 'a']++;
  }
  uint64_t i = 1;
  for (const auto n : alpha) {
    i *= n + 1;
    i = i % 1000000007;
  }
  std::cout << i - 1 << std::endl;
  return 0;
}
