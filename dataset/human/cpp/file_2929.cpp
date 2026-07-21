#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  int count_minus = 0;
  for (int i = 0; i < N; i++) if (A[i] < 0) count_minus++;
  sort(A.begin(), A.end(), [](int64_t a, int64_t b) {
      return abs(a) < abs(b);
    });

  int64_t result = 0;
  for (int i = 0; i < N; i++) {
    if ((count_minus & 1) && i == 0) {
      result -= abs(A[i]);
    } else {
      result += abs(A[i]);
    }
  }
  cout << result << endl;

  return 0;
}
