#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }
  
  int MxM = M * M;
  bool flg = false;
  for (int i = 0; i < N - M + 1; ++i) {
    if (flg) {
      break;
    }
    for (int j = 0; j < N - M + 1; ++j) {
      int cnt = 0;
      bool flg2 = true;
      for (int k = 0; k < M; ++k) {
        if (!flg2) {
          break;
        }
        for (int l = 0; l < M; ++l) {
          char N_p = A[i+k][j+l];
          char M_p = B[k][l];
          if (N_p == M_p) {
            ++cnt;
          } else {
            flg2 = false;
            break;
          }
        }
      }
      if (cnt == MxM) {
        flg = true;
        break;
      }
    }
  }
  if (flg) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
