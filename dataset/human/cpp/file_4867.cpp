#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, r;
  cin >> n >> r;

  if (n >= 10) {
    cout << r;
  } else {
    r += 100 * (10 - n);
    cout << r;
  }
  return 0;
}
