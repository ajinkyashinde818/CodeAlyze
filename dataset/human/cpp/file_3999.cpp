#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<((x))<<endl
#define fi first
#define se second

#define INF 2147483600
#define long long long
#define EPS 1e-8

// 浮動小数点誤差考慮
inline double add(double a, double b){
  if(abs(a+b) < EPS*(abs(a) + abs(b))) return 0;
  return a+b;
}

struct Point{
  double x,y;
  Point() {}
  Point(double nx, double ny) : x(nx), y(ny) {}
  inline Point operator + (const Point & p){ return Point(add(x, p.x), add(y, p.y)); }
  inline Point operator - (const Point & p){ return Point(add(x,-p.x), add(y,-p.y)); }
  inline Point operator * (double d){ return Point(x*d, y*d); }
  inline double dot(const Point & p){ return add(x * p.x, y*p.y); }  //内積
  inline double det(const Point & p){ return add(x * p.y, -y*p.x); } //外積
  inline double dist(const Point & p){ return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y)); }
  inline bool operator < (const Point & p) const {
    if(x != p.x) return x < p.x;
    else return y < p.y;
  }
  inline bool operator == (const Point & p) const {
    return (add(x, -p.x)==0) && (add(y, -p.y)==0);
  }
  friend ostream& operator<<(ostream& os, const Point& p) {
    os << "[" << p.x << "," << p.y << "]";
    return os;
  }
};

double d[1002][1002];

int main(){
  Point s,t;
  cin>>s.x>>s.y>>t.x>>t.y;
  int n;
  cin>>n;
  vector<Point> v(n+2);
  vector<double> r(n+2);
  rep(i,n) cin>>v[i].x>>v[i].y>>r[i];
  v[n]=s;
  v[n+1]=t;
  n+=2;

  fill(d[0], d[1000], INF);
  rep(i,n) repl(j,i+1,n){
    d[j][i] = d[i][j] = max<double>(0, v[i].dist(v[j])-r[i]-r[j]);
  }

  rep(k,n) rep(i,n) rep(j,n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

  printf("%.9f\n", d[n-2][n-1]);

  return 0;
}
