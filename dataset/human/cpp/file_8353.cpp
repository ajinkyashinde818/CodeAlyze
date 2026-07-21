#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
    vector<vector<char>> A(N,vector<char>(N)),B(M,vector<char>(M));
 for(int i=0;i<N;i++){
   for(int j=0;j<N;j++){
   cin>>A.at(i).at(j);
   }
      }
   for(int i=0;i<M;i++){
   for(int j=0;j<M;j++){
    cin>>B.at(i).at(j);
  }
   }
  bool ans=false;
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      bool check=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(A.at(i+k).at(j+l)!=B.at(k).at(l)){
            check=false;
            break;
          }
        }
        if(!check){
          break;
        }
      }
      if(check){
        cout<<"Yes"<<endl;
        ans=true;
        break;
      }
    }
    if(ans) break;
  }
   if(!ans) cout<<"No"<<endl;
 }
