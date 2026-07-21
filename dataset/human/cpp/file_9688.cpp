#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  char A[N][N];
  char B[M][M];
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> A[i][j];
    }
  }
  for(int i=0; i<M; i++){
    for(int j=0; j<M; j++){
      cin >> B[i][j];
    }
  }
  int cnt;
  for(int i=0; i<N-M+1; i++){
    for(int j=0; j<N-M+1; j++){
      cnt = 0;
      for(int k=0; k<M; k++){
        for(int l=0; l<M; l++){
          if(B[k][l] == A[i+k][j+l]){
            cnt++;
            if(cnt == M*M){
              cout << "Yes" <<endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
}
