#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  int cnt = 0;
  long long mn = 1LL << 60;
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    if (a[i] < 0) cnt += 1;
    mn = min(mn, abs(a[i]));
    sum += abs(a[i]);
  }
  if (cnt % 2 == 0)
    cout << sum << endl;
  else
    cout << sum - mn * 2 << endl;
}
