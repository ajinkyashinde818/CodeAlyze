#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<string> A(N),B(M);
  for(string &S:A) cin>>S;
  for(string &S:B) cin>>S;
  for(int i=0;i+M<=N;i++)
    for(int j=0;j+M<=N;j++){
      for(int k=0;k<M;k++)
        for(int l=0;l<M;l++)
          if(A[i+k][j+l]!=B[k][l]) goto home;
      cout << "Yes" << endl;
      return 0;
      home:;
    }
  cout << "No" << endl;
}
