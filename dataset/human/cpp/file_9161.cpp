#include <bits/stdc++.h>
using namespace std;

int main() {
  int M,N;
  cin>>M>>N;
  vector<vector<char>> p(M,vector<char>(M));
  vector<vector<char>> q(N,vector<char>(N));
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      cin>>p.at(i).at(j);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>q.at(i).at(j);
    }
  }
  int Z=0;
  for(int i=0;i<=M-N;i++){
    for(int j=0;j<=M-N;j++){
      int A=0;
      for(int k=0;k<N;k++){
        for(int l=0;l<N;l++){
          if(p.at(i+k).at(j+l)!=q.at(k).at(l)){
            A++;
            break;
          }
        }
        if(A==1){
          break;
        }
      }
      if(A==0){
        Z++;
        break;
      }
    }
    if(Z==1){
      break;
    }
  }
  if(Z==1){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  
}
