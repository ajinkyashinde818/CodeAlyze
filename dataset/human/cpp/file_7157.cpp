#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (0 < i) A[i] += A[i-1];
  }
  long ans = abs(A[0] - (A[N-1] - A[0]));
  for (int i = 1; i < N-1; i++) {
    long x = A[i], y = A[N-1] - A[i];
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
}
