#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

typedef pair<double,ll> pdl;

int main() {
  double xs,ys,xg,yg;
  cin >> xs >> ys >> xg >> yg;
  ll n;
  cin >> n;
  vector<double> x(n+2);
  vector<double> y(n+2);
  vector<double> r(n);
  x[n]=xs;
  y[n]=ys;
  x[n+1]=xg;
  y[n+1]=yg;
  vector<vector<double>> d(n+2,vector<double>(n+2));
  d[n][n+1]=d[n+1][n]=sqrt((x[n]-x[n+1])*(x[n]-x[n+1])+(y[n]-y[n+1])*(y[n]-y[n+1]));
  for(ll i=0;i<n;i++) cin >> x[i] >> y[i] >> r[i];
  for(ll i=0;i<n;i++) {
    for(ll j=i+1;j<n+2;j++) {
      if(i==j) {
        d[i][j]=d[j][i]=0;
      }
      else if(j>=n) {
        d[i][j]=d[j][i]=max(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[i],0.0);
      }
      else {
        d[i][j]=d[j][i]=max(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j],0.0);
      }
    }
  }
  vector<double> ans(n+2,-1);
  priority_queue<pdl,vector<pdl>,greater<pdl>> q;
  q.push(pdl(0.0,n));
  while(q.size()) {
    double td=q.top().first;
    ll f=q.top().second;
    q.pop();
    if(ans[f]>-1) continue;
    ans[f]=td;
    for(ll i=0;i<n+2;i++) {
      if(ans[i]<0.0) {
        q.push(pdl(ans[f]+d[f][i],i));
      }
    }
  }
  cout << fixed << setprecision(10) << ans[n+1] << endl;
}
