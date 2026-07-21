#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;cin>>N>>M;
  vector<vector<char>> a(N,vector<char>(N));
  vector<vector<char>> b(M,vector<char>(M));
  for(int i=0; i<N; i++){
    string s;cin>>s;
    for(int j=0; j<N; j++)a[i][j]=s[j];
  }
  for(int i=0; i<M; i++){
    string s;cin>>s;
    for(int j=0; j<M; j++)b[i][j]=s[j];
  }
  string ans="No";
  for(int i=0; i<N-M+1; i++){
    for(int j=0; j<N-M+1; j++){
      bool same=true;
      for(int x=0; x<M; x++){
        for(int y=0; y<M; y++){
          if(a[i+x][j+y]!=b[x][y])same=false;
        }
      }
      if(same)ans="Yes";
    }
  }
  cout<<ans<<endl;
}
