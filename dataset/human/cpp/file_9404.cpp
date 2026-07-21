#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  string A[50],B[50];
  int noexist=0;
  for(int i=0;i<N;i++) cin>>A[i];
  for(int i=0;i<M;i++) cin>>B[i];
  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      int judge=0;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(A[i+k][j+l]!=B[k][l]){
            judge++;
            l+=M;
          }
        }
      }
      if(judge==0){
        cout<<"Yes"<<endl;
        i+=2*N;
        j+=2*N;
        noexist++;
      }
    }
  }
  if(noexist==0) cout<<"No"<<endl;
  
  return 0;
}
