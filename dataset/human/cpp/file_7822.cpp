#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  vector<long> A(N);
  for (long i = 0; i < N; i++) cin >> A.at(i);
  vector<long> R(N + 1);
  for (long i = 1; i < N + 1; i++) {
    R.at(i) = R.at(i - 1) + A.at(i - 1);
  }
  long sum = R.at(N);
  long ans = 2e18;
  for (long i = 1; i < N; i++) {
    long tmp = sum - R.at(i);
    ans = min(ans, abs(tmp - R.at(i)));
  }
  cout << ans << "\n";
}
