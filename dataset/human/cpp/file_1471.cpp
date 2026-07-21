#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll k;
  for(ll i=1;;i++){
    if(i*(i-1)>2*n){
      cout<<"No"<<endl;
      return 0;
    }
    if(i*(i-1)==2*n){
      k=i;
      break;
    }
  }
  cout<<"Yes"<<endl;
  cout<<k<<endl;
  vector<ll> v[k];
  ll now=1;
  for(ll i=0;i<k;i++){
    for(ll j=i+1;j<k;j++){
      
      v[i].push_back(now);
      v[j].push_back(now);
      now++;
    }
  }
  for(ll i=0;i<k;i++){
    cout<<k-1<<" ";
    for(ll j=0;j<k-1;j++)cout<<v[i][j]<<" ";
    cout<<endl;
  }
}
