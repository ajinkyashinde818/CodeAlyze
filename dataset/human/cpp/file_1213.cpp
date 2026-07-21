#include<bits/stdc++.h>
using namespace std;
int main(){
  long long r,g,b,n,i,j,ans = 0;scanf("%lld%lld%lld%lld",&r,&g,&b,&n);
  for(i=0;r*i<=n;i++){
    for(j=0;r*i+g*j<=n;j++){
      if((n-r*i-g*j)%b==0) ans++;
    }
  }
  printf("%lld\n",ans);
}
