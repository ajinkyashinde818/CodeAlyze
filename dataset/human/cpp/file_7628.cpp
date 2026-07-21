#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long>A(N);
  for (long long i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<long long>Sum(N);
  Sum.at(0) = A.at(0);
  for (long long i = 1; i < N; i++) {
    Sum.at(i) = Sum.at(i - 1) + A.at(i);
  }
  long long ans = 3000000007;
  for (long long i = 0; i < N - 1; i++) {
    long long ABS = abs(Sum.at(N - 1) - Sum.at(i) - Sum.at(i));
    if (ans > ABS) ans = ABS;
  }
  cout << ans << endl;
}
