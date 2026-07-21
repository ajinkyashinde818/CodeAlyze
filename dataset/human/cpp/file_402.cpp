#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b,n,res=0;
  cin>>r>>g>>b>>n;
  for(int i=0;r*i<=n;++i){
    for(int j=0;g*j<=n;++j){
      if(n<r*i+g*j)break;
      if((n-r*i-g*j)%b==0)res++;
    }
  }
  cout<<res;
  return 0;
}
