#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M;
  cin >> N >> M;
  string A[N], B[M];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  for (int i = 0; i <= N-M; i++) {
    for (int j = 0; j <= N-M; j++) {
      bool valid = true;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (A[i+k][j+l] != B[k][l]) {
            valid = false;
          }
        }
      }
      if (valid) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
