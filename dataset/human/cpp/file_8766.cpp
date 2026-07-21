#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >>n>>m;
  int a[n][n];
  int b[m][m];
  string s;
  for(int i=0;i<n;i++){
    cin>>s;
    for(int j=0;j<n;j++){
      if(s[j]=='.')a[i][j]=0;
      else a[i][j]=1;
    }
  }
  for(int i=0;i<m;i++){
    cin>>s;
    for(int j=0;j<m;j++){
      if(s[j]=='.')b[i][j]=0;
      else b[i][j]=1;
    }
  }
  
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      bool hantei=true;
      for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l]){
            hantei=false;
            break;
          }
        }
        if(hantei==false)break;
      }
      if(hantei){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
