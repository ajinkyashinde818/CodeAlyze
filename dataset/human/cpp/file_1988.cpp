#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <iomanip>
using namespace std;


int main() {
  int n, a[100100];
  cin >> n;
  int num_neg = 0;
  int i_min_abs = 0;
  int v_min_abs = 1000000001;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      num_neg++;
    }
    if (abs(a[i]) < v_min_abs) {
      i_min_abs = i;
      v_min_abs = abs(a[i]);
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
      ans += abs(a[i]);
  }

  if (num_neg % 2 != 0) {
    ans -= v_min_abs * 2;
  }

  cout << ans << endl;



}
