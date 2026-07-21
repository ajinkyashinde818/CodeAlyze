// 2020-08-04 17:10:17
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n >> r;

  (n < 10) ? cout << r + (100 * (10 - n)) << endl : cout << r << endl;
  
  return 0;
}
