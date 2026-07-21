#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<char>> A(N,vector<char>(N));
  vector<vector<char>> B(M,vector<char>(M));
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
  bool match=false;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if((i+M-1>=N)||(j+M-1>=N)) continue;
      bool judge=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(A.at(i+k).at(j+l)!=B.at(k).at(l)) judge=false;
        }
      }
      if(judge==true) match=true;
    }
  }
  if(match==true)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
