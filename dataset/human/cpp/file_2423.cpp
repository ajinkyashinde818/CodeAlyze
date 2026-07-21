#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n,c=0; cin>>n;
  vector<ll> num(n);
  ll ans=0;
  for(int i=0;i<n;i++){
    ll x; cin>>x;
    if(x<0){
      c++;
      x*=-1;
    }num[i]=x;
    ans+=num[i];
  }if(c%2!=0){
    sort(num.begin(),num.end());
    ans-=2*num[0];
  }
  cout<<ans<<endl;
}
