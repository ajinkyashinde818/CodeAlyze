#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
P lft[100005]={P(0,0)},rit[100005]={P(0,0)};
ll lmax[100005]={0},rmax[100005]={0};
int main(){
  int n;
  cin>>n;
  ll c;
  cin>>c;
  vector<P> vec;
  for(int i=0;i<n;i++){
    ll x,v;
    cin>>x>>v;
    vec.push_back(P(x,v));
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<n;i++){
    lft[i+1].first=lft[i].first+vec[i].second;
    lft[i+1].second=vec[i].first;
    rit[n-(i+1)].first=rit[n-i].first+vec[n-(i+1)].second;
    rit[n-(i+1)].second=c-vec[n-(i+1)].first;
    lmax[i+1]=max(lmax[i],lft[i+1].first-lft[i+1].second);
    rmax[n-(i+1)]=max(rmax[n-i],rit[n-(i+1)].first-rit[n-(i+1)].second);
  }
  ll ans=0;
  for(int i=0;i<=n;i++) {
    ll lans=lft[i].first-lft[i].second;
    lans=max(lans,lans-lft[i].second+rmax[i]);
    ll rans=rit[i].first-rit[i].second;
    rans=max(rans,rans-rit[i].second+lmax[i]);
    ans=max({ans,lans,rans});
  }
  cout<<ans<<endl;
}
