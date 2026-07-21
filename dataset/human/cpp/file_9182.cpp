#include <iostream>
using namespace std;

const int MAX_N = 50;
const int MAX_M = 50;

int main() {
  int N, M;
  char A[MAX_N][MAX_N], B[MAX_M][MAX_M];
  bool ok = false;
  cin >> N >> M;
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      cin >> A[i][j];
    }
  }
  for (int i=0; i<M; i++){
    for (int j=0; j<M; j++){
      cin >> B[i][j];
    }
  }

  for (int i=0; i<=N-M; i++) {
    for (int j=0; j<=N-M; j++) {
      bool flag = true;
      for (int p=0; p<M; p++) {
        for (int q=0; q<M; q++) {
          if (A[i+p][j+q] != B[p][q]) {
            flag = false;
          }
        }
      }
      if (flag) ok = true;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
