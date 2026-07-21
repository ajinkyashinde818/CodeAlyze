#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  char a[n][n],b[m][m];
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
      cin>>b[i][j];

  bool exist=false;

  for(int i=0;i<n-m+1;i++){
    for(int t=0;t<n-m+1;t++){
      bool ans=true;
      for(int j=0;j<m;j++){
        for(int k=0;k<m;k++){
          if(a[i+j][t+k]!=b[j][k])
            ans=false;
        }
      }
        if(ans) exist=true;
    }
  }

  
  if(exist)
    cout<<"Yes";
  else cout<<"No";
        
    
}
