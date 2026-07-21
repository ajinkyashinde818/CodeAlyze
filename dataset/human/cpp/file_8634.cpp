#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<char>> A(200, vector<char>(200));
  vector<vector<char>> B(M, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cin >> A[i][j];
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) cin >> B[i][j];
  }
  
  bool can = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] != B[0][0]) continue;
      bool can2 = true;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (A[i+k][j+l] != B[k][l]) can2 = false;
        }
      }
      if (can2) can = true;
    }
  }
  
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
