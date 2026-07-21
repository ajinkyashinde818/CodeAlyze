#include <bits/stdc++.h>
using namespace std;
int u[2222222];
int main() {
  int n,m;
  cin >> n >> m;
  int a[m];
  for(int i=0;i<m;i++)cin>>a[i];
  for(int i=m-1;i>=0;i--) {
    if(!u[a[i]]) {
      u[a[i]]=1;
      cout<<a[i]<<endl;
    }
  }
  for(int i=1;i<=n;i++)if(!u[i])cout<<i<<endl;
  return 0;
}
