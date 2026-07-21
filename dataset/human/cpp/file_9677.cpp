#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  bool x;
  cin>>N>>M;
  vector<string>A(N),B(M);
  for(int i=0;i<N;i++)cin>>A.at(i);
  for(int i=0;i<M;i++)cin>>B.at(i);
  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      x=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(A.at(i+k).at(j+l)!=B.at(k).at(l)){
            x=false;
            break;
          }
        }
        if(!x)break;
      }
      if(x)break;
    }
    if(x)break;
  }
  if(x)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
