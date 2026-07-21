#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,a;
  cin>>N>>M;
  string A[N],B[M];
  for(int i=0;i<N;i++) cin>>A[i];
  for(int i=0;i<M;i++) cin>>B[i];
  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      a=1;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(B[k][l]!=A[i+k][j+l]){
            a=0;
            break;
          }
        }
        if(!a) break;
      }
      if(a) break;
    }
    if(a) break;
  }
  cout<<(a?"Yes":"No")<<endl;
}
