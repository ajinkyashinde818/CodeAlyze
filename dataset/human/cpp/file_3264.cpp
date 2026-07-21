#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  long ans = 0;
  int mi = 0;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int i=0; i<N; i++) {
    if (A[i] < 0) {
      mi++;
      A[i] = A[i] * -1;
    }
    if (A[i] == 0) {
      mi = 0;
      break;
    }
  }
  if (mi % 2 == 0) {
    for (int i=0; i<N; i++) {
      ans += abs(A[i]);
    }
  }
  else {
    sort(A.begin(),A.end());
    ans -= A[0]*2;
    for (int i=0; i<N; i++) {
      ans += abs(A[i]);
    }
  }
  cout << ans << endl;
}
