#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  cin >> n;

  vector<long> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long x = 0;
  long y = 0;
  long min = 0;
  x = a[0];
  for (int i = 1; i < n; i++) {
    y += a[i];
  }
  min = abs(x - y);

  long diff = 0;
  for (int i = 1; i < n - 1; i++) {
    x += a[i];
    y -= a[i];
    diff = abs(x - y);
    if (diff < min) {
      min = diff;
    }
  }

  cout << min << endl;

  return 0;
}
