#include<bits/stdc++.h>
using namespace std;
int main () {
  int N, M;
  cin >> N >> M;
  char mat[55][55];
  char mbt[55][55];
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < N; j ++) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < M; i ++) {
    for (int j = 0; j < M; j ++) {
      cin >> mbt[i][j];
    }
  }
  for (int i = 0; i <= N - M; i ++) {
    for (int j = 0; j <= N - M; j ++) {
      bool ok = true;
      for (int p = 0; p < M; p ++) {
        for (int q = 0; q < M; q ++) {
          if (mat[i + p][j + q] != mbt[p][q]) ok = false;
        }
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
