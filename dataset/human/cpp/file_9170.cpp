#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  char a[n][n],b[m][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    char c;
    cin>>c;
    a[i][j]=c;
    }
  }
   for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
    char c;
    cin>>c;
    b[i][j]=c;
    }
  }
  bool ans;
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      ans=true;
      for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l])ans=false;
        }
      }
      if(ans)break;
    }
    if(ans)break;
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
