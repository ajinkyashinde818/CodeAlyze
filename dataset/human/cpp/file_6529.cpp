#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ar[200005]={0},dr[200005]={0};
ll L,R,mod=1e9+7;
int main(){
  ll n;
  cin>>n;
  for(int i=1;i<=2*n;i++){
    char a;
    cin>>a;
    if(a=='B') ar[i]=1;
    else ar[i]=0;
  }
  if(ar[1]==0) {
    cout<<0<<endl;
    return 0;
  }
  dr[0]=0;
  dr[1]=0;
  for(int i=2;i<=2*n;i++){
    if(ar[i-1]==ar[i]) {
      dr[i]=(dr[i-1]+1)%2;
    }
    else{
      dr[i]=dr[i-1];
    }
  }
  for(int i=1;i<=2*n;i++){
    if(dr[i]==0) L++;
    else R++;
  }
  if(L!=R) {
    cout<<0<<endl;
    return 0;
  }
  ll ans=1;
  ll lnum=0;
  for(int i=1;i<=2*n;i++){
    if(dr[i]==0) lnum++;
    else{
      ans*=lnum;
      lnum--;
      ans%=mod;
    }
  }
  for(ll i=1;i<=n;i++) {
    ans*=i;
    ans%=mod;
  }
  cout<<ans<<endl;
}
