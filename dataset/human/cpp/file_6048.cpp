// D - Static Sushi O(N) 500
#include <iostream>
using namespace std;
using ll=long long;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll N,C;
  cin>>N>>C;
  ll x[N+2],v[N+2],sz[N+2],nz[N+2],sj[N+2],nj[N+2];
  for (int i=0; i<N+2; i++) {
    x[i]=v[i]=sz[i]=nz[i]=sj[i]=nj[i]=0;
  }
  for (int i=1; i<=N; i++) {
    cin>>x[i]>>v[i];
  }
  for (int i=1; i<=N; i++) {
    sj[i]=sj[i-1]+v[i];
    sz[i]=max(sz[i-1],sj[i]-x[i]);
  }
  for (int i=N; i>=1; i--) {
    nj[i]=nj[i+1]+v[i];
    nz[i]=max(nz[i+1],nj[i]-(C-x[i]));
  }
  ll ans=0;
  for (int i=1; i<=N; i++) {
    ans=max(ans,sz[i]);
    ans=max(ans,sj[i]+nz[i+1]-2*x[i]);
  }
  for (int i=N; i>=1; i--) {
    ans=max(ans,nz[i]);
    ans=max(ans,nj[i]+sz[i-1]-2*(C-x[i]));
  }
  cout<<ans<<endl;
  return 0;
}
