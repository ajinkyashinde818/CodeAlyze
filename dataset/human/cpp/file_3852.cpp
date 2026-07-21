#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
using namespace std; using ll=long long; using lld=long double;
const lld INF=1e32; using P=pair<lld,int>;

int main() {
  lld x0, y0, x1, y1; cin>>x0>>y0>>x1>>y1;

  int n; cin>>n; n+=2;
  lld x[n], y[n], r[n], t[n]; fill(t,t+n,INF);
  x[0]=x0; y[0]=y0; x[n-1]=x1; y[n-1]=y1; r[0]=r[n-1]=0;
  for(int i=1;i<n-1;i++) {
    cin>>x[i]>>y[i]>>r[i];
  }
  bool u[n]={};

  priority_queue<P, vector<P>, greater<P>> que; que.push({0.0,0}); t[0]=0; // len, id
  while(!que.empty()) {
    P d = que.top(); que.pop(); lld xx,yy,rr;

    if (t[d.second] < d.first) continue;
    xx = x[d.second]; yy = y[d.second]; rr = r[d.second]; u[d.second]=true;

    for(int i=0;i<n;i++) {
      if (u[i]) continue;
      lld pl = sqrt((xx-x[i]) * (xx-x[i]) + (yy-y[i]) * (yy-y[i]));
      pl = max((lld)0, pl - rr - r[i]);
      if (t[i] > d.first + pl) {
        t[i] = d.first + pl; que.push({t[i],i});
      }
      //cout<<d.second<<" "<<i<<" "<<d.first<<" "<<pl<<endl;
    }
  }

  cout<<fixed<<setprecision(10)<<t[n-1]<<endl;
}
