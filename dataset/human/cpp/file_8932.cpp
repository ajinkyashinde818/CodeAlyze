#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  char A[N][N+1];
  char B[M][M+1];
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < M; i++) {
    cin >> B[i];
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i + M > N || j + M > N) break;
      bool ok = true;
      for(int k = 0; k < M; k++) {
        for(int l = 0; l < M; l++) {
          if(A[i + k][j + l] != B[k][l]) {
            ok = false;
            k = M;
            break;
          }
        }
      }
      if(ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

}
