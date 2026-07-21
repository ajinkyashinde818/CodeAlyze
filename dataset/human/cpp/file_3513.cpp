#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long A[N];
  int minusCount = 0;
  long long minA = 1000000000;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] < 0) {
      minusCount++;
      A[i] = abs(A[i]);
    }
    minA = min(A[i], minA);
    ans += A[i];
  }

  if (minusCount % 2 == 1) {
    ans -= minA * 2;
  }

  cout << ans << endl;

  return 0;
}
