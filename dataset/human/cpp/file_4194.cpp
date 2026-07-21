#include<iostream>
#include<queue>
#include<bitset>
#include<algorithm>
#include<climits>
#include<vector>
#include<deque>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define fill(x,y) memset(x,y,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define dump(a) rep(i,a.size()){ cout<<a[i]<<" "; } cout<<endl;
#define dumparr(a,n) rep(i,n){ cout<<a[i]<<" "; } cout<<endl;
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define INF INT_MAX/3
#define EPS 1e-7

/* 基本的にダイクストラ
 * nodeをバリアの中心点、edgeを全点間に張って、その長さを(中心同士の距離-半径二つ)とする
 * O(n^2)
 */

int main(){
  ll xs,ys, xt,yt;
  ll n;
  ll x[1003], y[1003], r[1003];
  cin>>xs>>ys>>xt>>yt>>n;
  rep(i,n){
    cin>>x[i]>>y[i]>>r[i];
  }
  // x[0]~x[n-1]は点, x[n]がstart, x[n+1]がend
  x[n]=xs; y[n]=ys; r[n]=0;
  x[n+1]=xt; y[n+1]=yt; r[n+1]=0;

  // ダイクストラ
  double d[1003]; // sからの最小距離
  bool used[1003];
  rep(i,n+2) d[i]=1e200;
  fill(used, false);
  d[n] = 0;
  while(true) {
    /* dumparr(used, n+2); */
    /* dumparr(d,n+2); */
    ll v = -1; // 残ってるうちで最短のもの
    rep(i,n+2){
      if(!used[i] && (v == -1 || d[i] < d[v])) v = i;
    }
    /* dbg(v); */
    if(v==-1) break; // 終わり
    used[v] = true;
    rep(u,n+2) { 
      /* dbg(sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]))); */
      double dist = mmax(0, sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]))-r[u]-r[v]);
      d[u] = mmin( d[u], d[v]+dist );
    }
  }
  /* dumparr(d, n+2); */
  printf("%.10f\n", d[n+1]);

  return 0;
}
