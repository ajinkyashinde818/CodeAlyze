#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[100010], cnt_minus = 0, cnt_zero = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] < 0) {
      cnt_minus++;
      A[i] *= -1;
    }
    if (A[i] == 0) cnt_zero++;
  }

  long long ans = 0;
  int minv = 1 << 30;
  for (int i = 0; i < N; i++) {
    ans += A[i];
    minv = min(minv, A[i]);
  }
  if ((cnt_zero + cnt_minus) % 2 != 0) {
    ans -= minv * 2;
  }

  cout << ans << endl;
}
