#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< double, int > P;
const ll inf = numeric_limits< ll >::max()/3;
const double infd = numeric_limits< double >::max()/2;

struct circle{
  ll x;ll y;ll r;
};

vector< circle > C;
vector< vector< double > > G;

double res[1100];
priority_queue< P, vector<P>, greater<P> > que;

double dist(ll xa, ll ya,
	    ll xb, ll yb){
  return sqrt((xa-xb)*(xa-xb)
	      + (ya-yb)*(ya-yb));
}

int main(void){
  ll xs,ys;
  ll xt,yt;
  cin >> xs >> ys >> xt >> yt;
  int n;
  cin >> n;
  for(int i = 0;i < n;++i){
    ll x,y,r;
    cin >> x >> y >> r;
    circle cir = {x,y,r};
    C.push_back(cir);
  }
  circle cs = {xs,ys,0};
  circle ct = {xt,yt,0};
  C.push_back(cs);
  C.push_back(ct);
  n += 2;
  G.resize(n);
  for(int i = 0;i < n;++i)
    G[i].resize(n);
  for(int i = 0;i < n;++i){
    for(int j = i+1;j < n;++j){
      double d = max(0.0,
		     dist(C[i].x, C[i].y,
			  C[j].x, C[j].y)
		     - C[i].r - C[j].r);
      G[i][j] = d;
      G[j][i] = d;
    }
  }

  fill(res,res + 1100, infd);
  que.push(P(0, n-2));
  while(!que.empty()){
    double now_c = que.top().first;
    int now_n = que.top().second;
    que.pop();
    if(now_c < res[now_n]){
      res[now_n] = now_c;
      if(now_n == n-1){
	break;
      }
      for(int i = 0;i < n;++i){
	if(i != now_n &&
	   now_c + G[now_n][i] < res[i]){
	  que.push(P(now_c + G[now_n][i],
		     i));
	}
      }
    }
  }
  cout << setprecision(15) << res[n-1] << endl;
  return 0;
}
