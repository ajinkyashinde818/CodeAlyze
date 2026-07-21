#include<bits/stdc++.h>
using namespace std;
int used[200010];
int main(){
  int n,m;
  cin>>n>>m;
  int d[100010];
  for(int i=0;i<m;i++)cin>>d[i];
  for(int i=0;i<m;i++){
    if(used[d[m-1-i]])continue;
    used[d[m-1-i]]=1;
    cout<<d[m-1-i]<<endl;
  }
  for(int i=1;i<=n;i++){
    if(used[i])continue;
    used[i]=1;
    cout<<i<<endl;
  }
  return 0;
}
