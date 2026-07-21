#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
  ll r,g,b,n;
  cin>>r>>g>>b>>n;
  ll ans=0;
  for(int i=0;i<=n/r;i++){
          for(int j=0;j<=n/g;j++)
          {
             ll t=i*r+j*g;
             if(t>n) break;
             if((n-t)%b==0) ans++;
          }
  }
  
  cout<<ans<<endl;
  
}
