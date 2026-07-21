#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  long long int ans = 0;
  int idx = 0, cnt = 0;
  for (int i = 0; i < N; i++) {
    if (abs(A[i]) <= abs(A[idx])) {
      idx = i;
    }
    if (A[i] < 0) cnt++;
    ans += abs(A[i]);
  }
  if (cnt % 2 == 1) {
    ans -= 2 * abs(A[idx]);
  }
  cout << ans << endl;
}
