#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  long long mn = 1e9 + 1;
  int cnt_minus = 0;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    long long ab = abs(A[i]);
    sum += ab;
    mn = min(ab, mn);
    if (A[i] < 0) cnt_minus++;
  }
  if (cnt_minus % 2 == 0) {
    cout << sum << endl;
  } else {
    cout << sum - mn * 2 << endl;
  }
  return 0;
}
