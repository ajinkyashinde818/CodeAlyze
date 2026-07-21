#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
string str;
// Lib
int gcd(int x, int y) {
  int r;
  while ((r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y;
}
int lcm(int x, int y) {
  return (x * y / gcd(x, y));
}

int main() {
  cin >> str;
  // Parse
  string as, bs, cs;
  int pos;
  for (pos = 0; pos < str.size(); pos++) {
    if (str[pos] != '.') {
      as += str[pos];
    } else {
      break;
    }
  }
  for (pos++; pos < str.size(); pos++) {
    if (str[pos] != '(') {
      bs += str[pos];
    } else {
      break;
    }
  }
  for (pos++; pos < str.size(); pos++) {
    if (str[pos] != ')') {
      cs += str[pos];
    } else {
      break;
    }
  }

  pair<int, int> fd, id, ans;
  // 有限小数
  fd.first = atoi((as + bs).c_str());
  fd.second = pow(10, bs.size());
  // 無限小数
  if (cs.size() > 0) {
    id.first = atoi((cs).c_str());
    id.second = (pow(10, cs.size()) - 1) * pow(10, bs.size());
  } else {
    id.first = 0;
    id.second = 0;
  }
  // Answer
  if (cs.size() > 0) {
    ans.second = lcm(fd.second, id.second);
    ans.first = fd.first * (ans.second / fd.second) + id.first * (ans.second / id.second);
  } else {
    ans.second = fd.second;
    ans.first = fd.first;
  }
  int d = gcd(ans.first, ans.second);
  ans.first /= d;
  ans.second /= d;
  cout << ans.first << '/' << ans.second << '\n';
  return 0;
}
