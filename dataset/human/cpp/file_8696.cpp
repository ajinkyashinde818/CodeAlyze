#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  vector<vector<char>>A(N,vector<char>(N));
  vector<vector<char>>B(M,vector<char>(M));
  for(int i=0;i<N;i++){
    string S;cin>>S;
    for(int j=0;j<N;j++)A[i][j]=S.at(j);
  }
  for(int i=0;i<M;i++){
    string S;cin>>S;
    for(int j=0;j<M;j++)B[i][j]=S.at(j);
  }
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      bool b=true;
      for(int k=i;k<i+M;k++){
        for(int l=j;l<j+M;l++){
          if(A[k][l]!=B[k-i][l-j])b=false;
        }
        if(!b)break;
      }
      if(b){puts("Yes");return 0;}
    }
  }
  puts("No");
}
