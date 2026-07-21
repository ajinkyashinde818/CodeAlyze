#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;cin>>N>>M;
  char A[N][N];
  char B[M][M];
  for(int i=0;i<N;i++) cin>>A[i];
  for(int i=0;i<M;i++) cin>>B[i];
  bool can=false;
  for(int i=0;i<=N-M;i++){
    for(int l=0;l<=N-M;l++){
      bool isyes=true;
      for(int j=0;j<M;j++){
        for(int k=0;k<M;k++){
          if(A[i+j][k+l]!=B[j][k]){
            isyes=false;
            break;
          }
        }
        if(!isyes) break;
      }
      if(isyes){
        can=true;
        break;
      }
    }
    if(can) break;
  }
  cout<<(can?"Yes":"No")<<endl;
}
