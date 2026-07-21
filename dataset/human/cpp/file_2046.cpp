#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  int n_negative = 0;
  ll mi = 1e9 + 3;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    if (A[i] > 0) {
      sum += A[i];
      mi = min(mi, A[i]);
    }
    else {
      sum += (A[i] * -1);
      n_negative++;
      mi = min(mi, (A[i] * -1));
    }
  }
  if (n_negative % 2 == 0) {
    cout << sum << endl;
  } else {
    cout << sum - (mi * 2) << endl;
  }
  return 0;
}
