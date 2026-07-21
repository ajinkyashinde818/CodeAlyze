#include<bits/stdc++.h>

using namespace std;

int main(void){
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < M; i++) cin >> B[i];
  for(int i = 0; i + M <= N; i++){
    for(int j = 0; j + M <= N; j++){
      for(int ii = 0; ii < M; ii++){
        for(int jj = 0; jj < M; jj++){
          if(A[i + ii][j + jj] != B[ii][jj]) goto next;
        }
      }
      cout << "Yes" << endl;
      return 0;
      next:;
    }
  }
  cout << "No" << endl;
  return 0;
}
