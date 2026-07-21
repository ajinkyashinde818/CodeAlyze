#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

typedef vector<vector<pair<double,int>>> wgraph;
typedef pair<double,int> pli;

vector<double> bfs(wgraph v,int x){
  priority_queue<pli,vector<pli>,greater<pli>> q;
  vector<double> dist(v.size(),1e18);
  dist[x]=0;
  q.push({0LL,x});

  while(q.size()){
    pli p=q.top(); q.pop();
    double d=p.F;int now=p.S;
    if(dist[now]<d){ continue; }
    for(auto to:v[now]){
      if(dist[to.S]>d+to.F){
        dist[to.S] = d+to.F;
        q.push({dist[to.S], to.S});
      }
    }
  }
  return dist;
}


int main(){
  vector<int> x(1010,0),y(1010,0),r(1010,0);
  rep(i,2){
    cin >> x[i] >> y[i];
  }
  int n;
  cin >> n;
  n+=2;
  REP(i,2,n){
    cin >> x[i] >> y[i] >> r[i];
  }
  wgraph v(n);
  rep(i,n)rep(j,n)if(i!=j){
    double X = (x[i]-x[j]);
    double Y = (y[i]-y[j]);
    double z = sqrtl(X*X+Y*Y)-r[i]-r[j];
//    double z = hypot(x[i]-x[j],y[i]-y[j])-r[i]-r[j]; //どっちでも
    z = max(z,0.0);
    v[i].emplace_back(z,j);
  }
  vector<double> dist=bfs(v,0);
  double ans = dist[1];
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
