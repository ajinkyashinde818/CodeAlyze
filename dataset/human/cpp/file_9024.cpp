#include <bits/stdc++.h>
using namespace std;
int main() {
  bool ans = false;
  int N,M;
  cin >> N >> M;
  vector<vector<char> > A(N, vector<char>(N));
  vector<vector<char> > B(M, vector<char>(M));
  vector<vector<bool> > F(N - M + 1, vector<bool>(N - M + 1,true));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cin >> B[i][j];
    }
  }
  for (int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (A[i + k][j + l] != B[k][l]) {
             F[i][j] = false;
            }
          }
        }
      }
    }
  for (int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
        if (F[i][j] == true) {
          ans = true;
        }
      }
    }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
