#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

//common
typedef int  i32;
typedef long long i64,ll;
#define BR "\n"

#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

//config
#define MODE_DEBUG
//#define INF 1<<30
//#define EPS 1e-8
//const ll MOD =100000007;

//debug
#ifdef MODE_DEBUG
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl

#define  DUMP(x)  cerr << #x << " = " << (x) <<endl
#define DEBUG(x) DUMP(x) << " (L" << __LINE__ << ")" << " " << __FILE__<<endl
#define CHECK(exp,act)  if(exp!=act){DUMP(exp);DEBUG(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);
#else
#define DUMP(x)
#define DEBUG(x)
#define CHECK(exp,act)
#define STOP(e)
#endif

template<class T> inline string toString(const vector<T>& x) {
	stringstream ss;
	REP(i,x.size()){
		if(i!=0)ss<<" ";
		ss<< x[i];
	}
	return ss.str();
}
template<class T> inline string toString(const vector<vector<T>>& map) {
	stringstream ss;
	REP(i,map.size()){
		if(i!=0)ss<<BR;
		ss<< toString(map[i]);
	}
	return ss.str();
}
template<class K,class V>  string toString(map<K,V>& x) {
	string res;stringstream ss;
	for(auto& p:x)ss<< p.first<<":" << p.second<<" ";
	return ss.str();
}

template<typename T,typename V> inline T mod(T v,V MOD){
	return (v%MOD+MOD)%MOD;
}

const double EPS = 1e-9;

typedef complex<double> P;
typedef P vecP;
typedef vector<P> Polygon;

#define x(P) real(P)
#define y(P) imag(P)

struct L{
    P p1,p2;
    L(P p1,P p2):p1(p1),p2(p2){}
    vecP vec(){
        return p2-p1;
    }
};

struct C{
    P o;
    double r;
    C(P o,double r):o(o),r(r){}
};

namespace std{
    bool operator <(const P &lhs,const P &rhs){
        if(x(lhs) == x(rhs))
            return y(lhs) < y(rhs);
        return x(lhs) < x(rhs);
    }
}

// ベクタの長さ
double vector_length(P a){
    return abs(a);
}

// 二点間距離
double point_distance(P a,P b){
    return abs(a-b);
}

// 単位ベクトル
vecP unit_vector(vecP a){
    return a / abs(a);
}

// 法線ベクトル
pair<vecP,vecP> normal_vector(vecP a){
    return make_pair(a * vecP(0,1),a * vecP(0,-1));
}

// 点が一緒かどうか
bool Peq(P a,P b){
    return abs(a-b) < EPS;
}
// 内積 (dot product) : a・b = |a||b|cosΘ
double dot(vecP a,vecP b){
    return x(conj(a)*b);
}

// 外積 (cross product) : |a×b| = |a||b|sinΘ
double cross(vecP a,vecP b){
    return y(conj(a)*b);
}

// 直線と点との距離
double dist_line_and_point(L a,P b){
    return abs(cross(a.vec(),b-a.p1)) / abs(a.vec());
}

// 線分と点との距離
double dist_linesegment_and_point(L a,P b){
    if(dot(a.p2-a.p1,b-a.p1) < EPS) return abs(b-a.p1);
    if(dot(a.p1-a.p2,b-a.p2) < EPS) return abs(b-a.p2);
    return dist_line_and_point(a,b);
}

// a1,a2を端点とする線分(la)とb1,b2を端点(lb)とする線分の交差判定
bool is_intersected_linesegment(L a,L b){
    if(max(x(a.p1),x(a.p2)) + EPS < min(x(b.p1),x(b.p2))) return false;
    if(max(x(b.p1),x(b.p2)) + EPS < min(x(a.p1),x(a.p2))) return false;
    if(max(y(a.p1),y(a.p2)) + EPS < min(y(b.p1),y(b.p2))) return false;
    if(max(y(b.p1),y(b.p2)) + EPS < min(y(a.p1),y(a.p2))) return false;
    return cross(a.vec(),b.p1-a.p1)*cross(a.vec(),b.p2-a.p1) < EPS  && cross(b.vec(),a.p1-b.p1)*cross(b.vec(),a.p2-b.p1) < EPS;
}

// a1,a2を端点とする線分(la)とb1,b2を端点とする線分(lb)の交点計算
P intersection_point_linesegment(L a,L b){
    if(a.p1 == b.p1 or a.p1 == b.p2) return a.p1;
    if(a.p2 == b.p1 or a.p2 == b.p2) return a.p2;
    double d1 = abs(cross(b.vec(), a.p1-b.p1)),d2 = abs(cross(b.vec(), a.p2-b.p1));
    double t = d1 / (d1 + d2);
    return a.p1 + (a.p2-a.p1) * t;
}

// 線分同士の最短距離
double dist_linesegment_and_linesegment(L a,L b){
    if(is_intersected_linesegment(a,b))return 0;

    return min(min(dist_linesegment_and_point(a,b.p1),dist_linesegment_and_point(a,b.p2) ),
    min(dist_linesegment_and_point(b,a.p1),dist_linesegment_and_point(b,a.p2)));
}


// 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
// みけんしょう
bool is_orthogonal(L a,L b) {
    return dot(a.vec(),b.vec()) < EPS;
}
// 2直線の平行判定 : a//b <=> cross(a, b) = 0
bool is_parallel(L a,L b) {
    return abs(cross(a.vec(),b.vec())) < EPS;
}

// a1,a2を通る直線とb1,b2を通る直線の交差判定
bool is_intersected_line(L a,L b) {
    return !is_parallel(a,b);
}

// a1,a2を通る直線とb1,b2を通る直線の交点計算
P intersection_line(L a,L b) {
    return a.p1 + a.vec() * cross(b.vec(), b.p1-a.p1) / cross(b.vec(), a.vec());
}



// 直線と点の最短距離を実現する直線の点(すいせんの足)(みけんしょう)
P nearest_point_line_and_point(L a,P b){
    return a.p1 + a.vec() * dot(a.vec(),b-a.p1) / norm(a.vec());
}

// 線分と点の最短距離を実現する線分嬢の点(みけんしょう)
P nearest_point_linesegment_and_point(L a,P b){
    if(dot(a.vec(),b-a.p1) < EPS) return a.p1;
    if(dot(a.vec(),b-a.p2) < EPS) return a.p2;
    return nearest_point_line_and_point(a,b);
}
// 円と線分の交差判定
bool is_cross_linesegment_and_circle(C c,L a){
    return (dist_linesegment_and_point(a,c.o) < c.r+EPS &&
       (c.r < abs(c.o-a.p1) + EPS || c.r < abs(c.o-a.p2) + EPS));
}

int main(){
	while(true){
		int N;cin >> N;
		if(N==0)break;
		vector<C> cs;
		REP(i,N){
			int x,y,r;cin >> x >> y >> r;
			cs.push_back(C(P(x,y),r));
		}

		int M;cin >> M;
		REP(c,M){
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			L l=L(P(x1,y1),P(x2,y2));
			//intersect
			bool cross=false;
			REP(i,N){
				if(is_cross_linesegment_and_circle(cs[i], l))cross=true;
			}
			cout << (cross?"Safe":"Danger")<<endl;
		}
	}
	return 0;
}
