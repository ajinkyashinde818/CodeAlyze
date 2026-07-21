#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<ll,ll>;
using vi = vector<ll>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV int(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
 
/* Coding Space*/
typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

typedef vector<P> G;

struct C {
  P p; double r;
};
C circles[1002];
double table[1002][1002] = {};

int main(){
  double xs,ys,xt,yt; cin >> xs >> ys >> xt >> yt;
  int n; cin >> n;
  circles[0] = C{P{xs,ys},0};
  circles[1] = C{P{xt,yt},0};
  for(int i = 2; i < n + 2;i++){
    double x,y,r; cin >> x >> y >> r;
    circles[i] = C{P{x,y},r};
  }
  rep(i,n+2)rep(j,n+2){
    if(i == j) table[i][j] = 0.;
    else{
      table[i][j] = max(0.,abs(circles[i].p - circles[j].p) - circles[i].r - circles[j].r);
      //cerr << i << " " << j << " " << table[i][j] << endl;
    }
  }
  using tdi = tuple<double,int>; // cost,index
  priority_queue<tdi,vt<tdi>,greater<tdi>> q;
  q.push(tdi{0.0,0});
  bool used[1002] = {};
  while(1){
    double cost; int index; tie(cost,index) = q.top(); q.pop();
    if(used[index]) continue;
    if(index == 1) {
      cout << fixed << setprecision(20) << cost << endl;
      return 0;
    }else{
      rep(i,n+2){
        if(i != index)
          q.push(tdi{table[index][i] + cost,i});
      }
    }
    used[index] = 1;
  }
}
