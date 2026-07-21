#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<numeric>
#include<cassert>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define print(x) printf("%d\n",x)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

#include<complex>

#define EPS 1e-10

using std::complex;
typedef complex<double> P; /* _ */

static inline bool eq(const P &a, const P &b){
  return abs(a-b) < EPS;
}
/* àÏ */
static inline double inp(const P &a, const P &b){
  return (conj(a)*b).real();
}
/* OÏ */
static inline double outp(const P &a, const P &b){
  return (conj(a)*b).imag();
}

class Line{
public:
  P p; /* position */
  P d; /* direction */
  Line(){}
  Line(P pos, P dir){p=pos; d=dir/abs(dir);}
};

/* _Æûü©ç */
Line LineDirect(P pos, P dir){
  return Line(pos, dir);
}
/* 2_©ç */
Line LinePos(P p1, P p2){
  return Line(p1, p2-p1);
}

/* 2ÂÌ¼üÌð_ */
P crossPoint(const Line &l1, const Line &l2){
  double num = outp(l2.d, l2.p-l1.p);
  double denom = outp(l2.d, l1.d);
  return P(l1.p + l1.d * num/denom);
}

/* _Æ¼üÌ£ */
double dist(const Line &l, const P &p){
  return std::abs(outp(l.d, p-l.p) / abs(l.d));
}

/* p0, p1, p2ª
 * ½vñè:  1
 * vñè  : -1
 *
 * R_ª¼üãÉ éê
 * p0ªp2Æp1ÌÔÉ é: -1
 * p2ªp0Æp1ÌÔÉ é:  0
 * p1ªp0Æp2ÌÔÉ é:  1
 */
int ccw(P p0, P p1, P p2){
  P d1 = p1-p0;
  P d2 = p2-p0;
  double dx1 = d1.real(), dx2 = d2.real();
  double dy1 = d1.imag(), dy2 = d2.imag();

  if(dx1*dy2 > dy1*dx2) return  1;//½vñè
  if(dx1*dy2 < dy1*dx2) return -1;//vñè
  if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
  if((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return 1;
  return 0;
}

template<class T> 
inline T dbl(T x){ return x * x; }

int main(){
  int n;
  while(n = getInt()){
    vector<P> c(n);
    vector<int> r(n);

    REP(i,n){
      c[i].real() = getInt();
      c[i].imag() = getInt();
      r[i]        = getInt();
    }

    int m = getInt();

    REP(cc,m){
      P tarou;
      P oni;

      tarou.real() = getInt();
      tarou.imag() = getInt();
      oni.real() = getInt();
      oni.imag() = getInt();

      bool ans = true;

      REP(i,n){
	bool tarouIn = ((int)(abs(tarou - c[i])+EPS)) < r[i];
	bool oniIn = ((int)(abs(oni - c[i])+EPS)) < r[i];

	if(tarouIn != oniIn){
	  ans = false;
	  break;
	}

	if(!tarouIn){
	  Line to(LinePos(tarou, oni));
	  if(((int)(dist(to, c[i]) - EPS)) < r[i]){
	    Line co(LineDirect(c[i], to.d * P(0, 1.0)));
	    P cross(crossPoint(to, co));
	    
	    double rate = ((oni - tarou) / (cross - tarou)).real();

	    if(rate >= 1.0){
	      ans = false;
	      break;
	    }
	  }
	}
      }

      puts(ans ? "Danger" : "Safe");
    }
 
  }
  return 0;
}
