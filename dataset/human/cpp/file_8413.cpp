#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<string> A(N),B(M);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  for(int i=0;i<M;i++){
    cin>>B.at(i);
  }
  
  bool flag=false;
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      flag=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(A.at(i+k).at(j+l)!=B.at(k).at(l)){
            flag=false;
            break;
          }
        }
        if(!flag){
          break;
        }
      }
      if(flag){
        break;
      }
    }
    if(flag){
      break;
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
