#include<iostream>
using namespace std;
int n,m;
bool check(string a[],string b[],int sx,int sy){
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      if(a[sx+i][sy+j]!=b[i][j])return false;
    }
  }
  return true;
}
int main(){
  cin >> n >> m;
  string a[n],b[m];
  bool ans=false;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<m;i++){
    cin >> b[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i+m<=n&&j+m<=n){
        ans = check(a,b,i,j);
        if(ans) break;
      }
    }
    if(ans) break;
  }
  if(ans) cout <<"Yes\n";
  else cout <<"No\n";
}
