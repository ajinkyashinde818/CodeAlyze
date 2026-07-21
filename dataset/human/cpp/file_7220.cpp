#include <bits/stdc++.h>
using namespace std;
int main () {
  long N;
  cin >> N;
  vector<int> data(N);
  long sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> data.at(i);
    sum += data.at(i);
  }
  long x = 0, y = sum, ans = 10000000000,a = 0;
  for (int i = 0; i < N - 1; i++) {
    y -= data.at(i);
    x = sum - y;
    a = abs(x - y);
    if (ans > a) ans = a;
  }
  cout << ans << endl;
  return 0;
}
