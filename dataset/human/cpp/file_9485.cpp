#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> A(N, vector<char>(N)), B(M, vector<char>(M));
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> A[i][j];
    }
  }
  for (int i=0; i<M; i++) {
    for (int j=0; j<M; j++) {
      cin >> B[i][j];
    }
  }
  string ans="No";
  int same=1;
  for (int i=0; i<=N-M; i++) {
    for (int j=0; j<=N-M; j++) {
      same=1;
      for (int k=0; k<M; k++) {
        for (int l=0; l<M; l++) {
          if (A[i+k][j+l]!=B[k][l]) {
            same=0;
          }
        }
      }
      if (same==1) {
        ans = "Yes";
        break;
      }
    }
    if (same==1) {break;}
  }
  cout << ans << endl;
}
