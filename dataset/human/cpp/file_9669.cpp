#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  char a[n][n],b[m][m];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>a[i][j];
    }
  }
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      cin>>b[i][j];
    }
  }
  int cnt=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i+m-1>=n||j+m-1>=n)continue;
      for(int k=0; k<m; k++){
        for(int l=0; l<m; l++){
          if(b[k][l]==a[i+k][j+l]){
            cnt++;
          }
        }
      }
      	if(cnt==m*m){
          cout<<"Yes"<<endl;
          return 0;
        }
        cnt=0;
    }
  }
  cout<<"No"<<endl;
}
