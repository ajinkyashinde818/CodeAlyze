#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
string a[55],b[55];
int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];
  bool ok=false;
  for(int i=0;i<n;i++)if(i+m-1<n){
    for(int j=0;j<n;j++)if(j+m-1<n){
      ok=true;
      for(int k=0;k<m && ok;k++){
        for(int l=0;l<m && ok;l++){
          if(a[i+k][j+l]!=b[k][l])ok=false;
        }
      }

      if(ok){
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}
