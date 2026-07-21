#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  char A[N][N];
  char B[M][M];
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++) cin >> A[i][j];
  }
  for(int i=0; i<M; i++){
    for(int j=0; j<M; j++) cin >> B[i][j];
  }
  int ans=0;
  if(N==M){
    int cnt=0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(A[i][j]==B[i][j]) cnt++;
      }
    }
    if(cnt==N*N) ans++;
  }
  else{
    for(int i=0; i<N-M; i++){
    for(int j=0; j<N-M; j++){
      int cnt=0;
      for(int k=0; k<M; k++){
        for(int l=0; l<M; l++){
          if(A[k+i][l+j]==B[k][l]) cnt++;
        }
      }
      if(cnt==M*M) ans++;
    }
  }
  }
  if(ans>0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
