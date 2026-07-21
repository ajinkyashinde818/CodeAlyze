#include<bits/stdc++.h>
using namespace std;

int main(){
  int M, N;
  string A[50];
  string B[50];
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<M; i++) cin >> B[i];
  for(int i=0; i<N-M+1; i++){
    for(int j=0; j<N-M+1; j++){
      bool flag = true;
      for(int k=0; k<M; k++){
        for(int l=0; l<M; l++){
          if(A[i+k][j+l]!=B[k][l]){
            flag = false;
            break;
          }
        }
        if(!flag) break;
      }
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
