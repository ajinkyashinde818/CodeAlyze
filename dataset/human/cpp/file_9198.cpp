#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; ++i) cin >> B[i];

  for (int i = 0; i <= N - M; ++i) {
    for (int ii = 0; ii <= N - M; ++ii) {
      bool isValid = true;
      for (int j = 0; j < M; ++j) {
	for (int k = 0; k < M; ++k) {
	  if (A[i + j][k + ii] != B[j][k]) isValid = false;
	}
      }
      if (isValid) {
	cout << "Yes" << endl;
	return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
