#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >>N>>M;
  char A[N][N];
  char B[M][M];
  string temp;
  
  //A入力
  for(int i=0;i<N;i++){
    cin>>temp;
    for (int j=0;j<N;j++){
      A[i][j]=temp.at(j);
    }
  }
  //B入力
  for(int i=0;i<M;i++){
    cin>>temp;
    for (int j=0;j<M;j++){
      B[i][j]=temp.at(j);
    }
  }  
  
  //判定
  for(int k=0;k<=N-M;k++){
    for(int l=0;l<=N-M;l++){
      bool flag=0;
      
      for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
          if(B[i][j]!=A[i+k][j+l]){
            //cout<<B[i][j]<<A[j+k][j+l]<<i<<j<<k<<l<<"#"<<flag<<endl;
            flag=1;
          }
        }
        
        if(flag){
          break;
        }
      }
      if(flag){
        continue;
      }
      else {
      cout<<"Yes"<<endl;
      return 0;
      }
    }
  }
  cout<<"No"<<endl;

  return 0;
}
