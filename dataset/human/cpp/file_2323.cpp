#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
vector<long long> A;

int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int abs_min_idx = 0;
  long long abs_min = LONG_LONG_MAX;
  for (int i = 0; i < N; i++) {
    if (abs_min > abs(A[i])) {
      abs_min_idx = i;
      abs_min = abs(A[i]);
    }
  }

  for (int i = 0; i < abs_min_idx; i++) {
    if (A[i] < 0) {
      A[i] = -A[i];
      A[i + 1] = -A[i + 1];
    }
  }
  for (int i = N - 1; i > abs_min_idx; i--) {
    if (A[i] < 0) {
      A[i] = -A[i];
      A[i - 1] = -A[i - 1];
    }
  }

  cout << accumulate(A.cbegin(), A.cend(), 0LL) << endl;
  return 0;
}
