#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] < 0) cnt++;
  }

  for (int i = 0; i < N; i++)
    if (A[i] < 0) A[i] = -A[i];

  if (cnt % 2 == 1) {
    cout << accumulate(A.begin(), A.end(), 0LL) -
                *min_element(A.begin(), A.end()) * 2
         << endl;
  } else {
    cout << accumulate(A.begin(), A.end(), 0LL) << endl;
  }
  return 0;
}
