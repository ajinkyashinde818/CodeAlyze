#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  long long sum = 0;
  int cnt = 0;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    if (A[i] < 0) cnt++;
    sum += abs(A[i]);
  }

  long long minval = sum;
  for (int i=0; i<N; i++) {
    long long a = abs(A[i]);
    minval = min(minval, a);
  }

  if (cnt % 2 == 0) {
    cout << sum << endl;
  } else {
    cout << (sum-minval) - minval << endl;
  }

  return 0;
}
