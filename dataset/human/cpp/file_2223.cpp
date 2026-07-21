#include <iostream>
using namespace std;
int main()
{
  int n, v;
  long t = 0;
  int m = 0;
  int x = 1000000000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v;
    if (v < 0) {
      v = -v;
      m++;
    }
    t += v;
    if (x > v) {
      x = v;
    }
  }
  if (m & 0x01) {
    t -= x * 2;
  }
  cout << t << endl;
  return 0;
}
