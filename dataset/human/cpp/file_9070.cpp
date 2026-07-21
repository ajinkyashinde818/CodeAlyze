#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<char>> a(n,vector<char> (n));
  vector<vector<char>> b(m,vector<char> (m));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      cin >> b[i][j];
    }
  }
  bool c=false;
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      bool ans=true;
      for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
          if(b[k][l]!=a[i+k][j+l]){
            ans=false;
          }
        }
      }
      if(ans){
        c=true;
      }
    }
  }
  if(c){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
