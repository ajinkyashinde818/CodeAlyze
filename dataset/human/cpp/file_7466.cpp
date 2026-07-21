#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll num = 0, sub = 2000000001;
  for (int i = 0; i < N; i++) {
    num += a[i];
    if (abs(sum - 2*num) < sub) sub = abs(sum - 2*num);
    if (i == N-2) break;
  }
  cout << sub << endl;
}
