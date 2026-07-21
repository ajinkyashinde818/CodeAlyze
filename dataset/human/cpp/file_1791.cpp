#include <iostream>
#include <algorithm>
using namespace std;
int main(){

  int n,m,e[100000],nf[200001]={};

  cin>>n>>m;
  for(int i=0;i<m;i++) cin>>e[i];
  reverse(e,e+m);
  for(int i=0;i<m;i++){
    if(nf[e[i]]) continue;
    cout<<e[i]<<endl;
    nf[e[i]]=1;
  }
  for(int i=1;i<=n;i++) if(!nf[i]) cout<<i<<endl;
  return 0;

}
