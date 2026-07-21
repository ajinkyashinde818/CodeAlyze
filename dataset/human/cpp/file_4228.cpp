#include <iostream>

using namespace std;

long long x3[50];

int main() {
  long long t;
  while (cin >> t) {
    if (t == 0) { cout << 0 << endl; continue; }
    int cnt = 1;
    long long remain = t;
    int i = 0;
    x3[i] = 1;
    while (x3[i] * 4 <= remain) {
      remain -= x3[i] * 4;
      x3[i+1] = x3[i] * 3;
      ++i;
      cnt += 2;
    }
    // cout << i << " " << cnt << " " << remain << endl;
    for (int j = i; j >= 0; --j) {
      cnt += remain / x3[j];
      remain %= x3[j];
    }
    cout << cnt-1 << endl;
  }
}
