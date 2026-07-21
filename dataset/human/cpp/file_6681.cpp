#include<iostream>
#include<sstream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cfloat>
#include<functional>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<bitset>
#include<list>
#include<numeric>
#include<complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<long long, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<long long, long long> ll_ll;
typedef pair<double, double> d_d;
typedef vector<int> Vint;

#define PI 3.141592653589793238462643383279
#define mod 1000000007LL
#define rep(i, n) for(i = 0;i < n;++i)
#define rep1(i, n) for(i = 1;i < n;++i)
#define rep2d(i, j, n) for(i = 0;i < n;++i)for(j = i + 1;j < n;++j)
#define per(i, n) for(i = n - 1;i > -1;--i)
#define int(x) int x; scanf("%d",&x)
#define int2(x, y) int x, y; scanf("%d%d",&x, &y)
#define int3(x, y, z) int x, y, z; scanf("%d%d%d",&x, &y, &z)
#define int4(v, x, y, z) int v, x, y, z; scanf("%d%d%d%d", &v, &x, &y, &z)
#define int5(v, w, x, y, z) int v, w, x, y, z; scanf("%d%d%d%d%d", &v, &w, &x, &y, &z)
#define scn(n, a) rep(i, n)cin >> a[i]
#define sc2n(n, a, b) rep(i, n)cin >> a[i] >> b[i]
#define pri(x) cout << x << "\n"
#define pri2(x, y) cout << x << " " << y << "\n"
#define pri3(x, y, z) cout << x << " " << y << " " << z << "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define endl "\n"
#define kabe puts("---------------------------")
#define kara puts("")
#define debug(x) cout << " --- " << x << "\n"
#define debug2(x, y) cout << " --- " << x << " " << y << "\n"
#define debug3(x, y, z) cout << " --- " << x << " " << y << " " << z << "\n"
#define X first
#define Y second
#define eps 0.0001
#define prid(x) printf("%.15lf\n", x)

double xmax, xmin, ymax, ymin;
struct vec{
  double x, y;
  vec operator+(const vec& a) const { return (vec){x + a.x, y + a.y}; }
  vec operator-(const vec& a) const { return (vec){x - a.x, y - a.y}; }
  vec sca(double t){ return (vec){t * x, t * y}; }
  double dot(vec a){ return x * a.x + y * a.y; }
  double cross(vec a){ return x * a.y - y * a.x; }
  double norm(){ return sqrt(x * x + y * y); }
  double norm2(){ return x * x + y * y; }
};
struct line{
  vec a, b;
  void nextline(){ cin >> a.x >> a.y >> b.x >> b.y; return; }
  vec getvec(){ return b - a; }
  double size(){ return getvec().norm(); }
  vec proj(vec p){ return a + (b - a).sca((p - a).dot(b - a) / (b - a).dot(b - a)); }
  vec vref(vec p){ return proj(p).sca(2.0) - p; }
  int ccw(vec p){
    vec q = p - a, ba = b - a;
    if(ba.cross(q) > 0)return 1; //ccw
    if(ba.cross(q) < 0)return -1; //cw
    if(ba.dot(q) < 0)return -2; //back
    if(ba.dot(ba) < q.dot(q))return 2; //front
    return 0; //on
  }
  bool paral(line l){ return abs(l.getvec().cross(getvec())) < eps; }
  bool orth(line l){ return abs(l.getvec().dot(getvec())) < eps; }
  bool intersec(line l){
    bool res0 = (ccw(l.a) * ccw(l.b) == 4); //syukutai
    bool res1 = (getvec().cross(l.a - a) * getvec().cross(l.b - a)) <= eps;
    bool res2 = (l.getvec().cross(a - l.a) * l.getvec().cross(b - l.a)) <= eps;
    return !res0 && res1 && res2;
  }
  vec crosspoint(line l){
    return a + getvec().sca((l.a - a).cross(l.getvec()) / getvec().cross(l.getvec()));
  }
  double pldist(vec p){
    double res = min((a - p).norm2(), (b - p).norm2());
    vec h = proj(p);
    if((a - h).dot(b - h) < 0)res = min(res, (h - p).norm2());
    return sqrt(res);
  }
  double lldist(line l){
    if(intersec(l))return 0.0;
    return min(min(pldist(l.a), pldist(l.b)), min(l.pldist(a), l.pldist(b)));
  }
};
struct circle{
  vec o;
  double r;
  void nextcir(){ cin >> o.x >> o.y >> r; return; }
  int ccintersec(circle c){
    double d = (o - c.o).norm(), rp = r + c.r, rm = abs(r - c.r);
    if(abs(rp - d) < eps)return 3;
    if(rp < d + eps)return 4;
    if(abs(rm - d) < eps)return 1;
    if(rm < d + eps)return 2;
    return 0;
  }
  int clintersec(line l){
    double d = l.pldist(o);
    if(abs(d - r) < eps)return 1; //on
    if(d < r)return 2;  //in
    return 0; //out
  }
};

circle c[100];

signed main(void){
  int i, j, k;
  for(int testcase = 0;testcase >= 0;testcase++){
    int(n); if(!n)break;
    rep(i, n)c[i].nextcir();
    int(m);
    for(;m--;){
      line l; l.nextline();
      rep(i, n){
        double mi = l.pldist(c[i].o), ma = max((l.a - c[i].o).norm(), (l.b - c[i].o).norm());
        if(mi <= c[i].r + eps && c[i].r < ma + eps)break;
      }
      puts(i < n ? "Safe" : "Danger");
    }
  }
  return 0;
}
