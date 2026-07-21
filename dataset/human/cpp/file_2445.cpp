#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long int *a;
  int n, i, j, s;
  long long int m;
  long long int ma;  // minimum a value
  int mi;            // minimum a index;
  cin >> n;
  a = (long long int *)malloc(sizeof(long long int) * n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  s = 0;
  ma = abs(a[0]);
  mi = 0;
  for (i = 0; i < n; i++) {
    if (abs(a[i]) < ma) {
      ma = abs(a[i]);
      mi = i;
    }
    if (a[i] < 0) {
      s++;
    }
  }
  // cout << mi << " " << ma << endl;
  for (i = 0; i < n; i++) {
    if (a[i] < 0) {
      a[i] = -a[i];
    }
  }
  if (s % 2 == 1) {
    a[mi] = -ma;
  }
  m = 0;
  for (i = 0; i < n; i++) {
    // cout << "A:" << a[i] << " ";
    m += a[i];
  }
  cout << m << endl;
  return 0;
}
