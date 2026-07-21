// #includes {{{
#include <algorithm>
#include<complex>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

typedef long long Int;
typedef unsigned long long uInt;
#ifdef __MINGW32__
typedef double rn;
#else
typedef long double rn;
#endif

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

const rn INF=1.0L/0.0L;

//{{{ Graph
typedef rn Weight;
struct Edge {
	int src, dst, rev;
	Weight weight;
	Edge(int src, int dst, Weight weight=1,int rev=-1) :
		src(src), dst(dst), weight(weight), rev(rev) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
		e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

//add bi-directional edge
void addBiEdge(Graph &g,int from ,int to, Weight w=1){
	while(g.size()<max(from,to)+1)g.push_back(Edges());
	g[from].push_back(Edge(from,to,w,g[to].size()));
	g[to].push_back(Edge(to,from,w,g[from].size()-1));
}
//add directional edge
void addEdge(Graph &g,int from ,int to, Weight w=1){
	while(g.size()<from+1)g.push_back(Edges());
	g[from].push_back(Edge(from,to,w));
}
#ifdef DEBUG
#include"graph/graphviz.h"
#endif
//}}}
//{{{ Dijkustra Shortest Path
void shortestPath(const Graph &g, int s,
		vector<Weight> &dist, vector<int> &prev) {
	const int n = g.size();
	dist.assign(n, INF); dist[s] = 0;
	prev.assign(n, -1);
	priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
	for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
		Edge e = Q.top(); Q.pop();
		if (prev[e.dst] != -1) continue;
		prev[e.dst] = e.src;
		FOR(f,g[e.dst]) {
			if (dist[f->dst] > e.weight+f->weight) {
				dist[f->dst] = e.weight+f->weight;
				Q.push(Edge(f->src, f->dst, e.weight+f->weight));
			}
		}
	}
}
vector<int> buildPath(const vector<int> &prev, int t) {
	vector<int> path;
	for (int u = t; u >= 0; u = prev[u])
		path.push_back(u);
	reverse(path.begin(), path.end());
	return path;
}
//}}}

//{{{ Geometry Components
#include<complex>
const rn PI=3.141592653589793238462643383279L;
const rn EPS=1e-10;

inline int signum(rn x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }

// point
typedef complex<rn> P;
namespace std {
	bool operator < (const P& a, const P& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
// line
struct L {
	P pos, dir; 
	L(const P &pos,const P &dir):pos(pos),dir(dir){}
	P operator[](int i)const {
		if(i==0)return pos;
		else return pos+dir;
	}
};
L line_PP(const P &p,const P &q){
	return L(p,q-p);
}
// polygon
typedef vector<P> G;
// circle
struct C { 
	P p; rn r;
	C(const P &p,const rn r):p(p),r(r){}
};
G triangle(const P &p,const P &q,const P &r){
	G g;
	g.push_back(p);
	g.push_back(q);
	g.push_back(r);
	return g;
}

P unit_vector(const P &p){
	return p/abs(p);
}
//}}}

rn xs,ys,xt,yt;
rn x[1010],y[1010],r[1010];
P p[1010];
int N;

int main(){
	scanf("%Lf%Lf%Lf%Lf",&xs,&ys,&xt,&yt);
	P ps(xs,ys),pt(xt,yt);
	scanf("%d",&N);
	int s=N,t=N+1;
	REP(i,N)scanf("%Lf%Lf%Lf",x+i,y+i,r+i);
	REP(i,N)p[i]=P(x[i],y[i]);
	Graph g(N+2);
	REP(i,N)RREP(j,i+1,N){
		rn d = max(abs(p[i]-p[j])-r[i]-r[j],0.0L);
		addBiEdge(g,i,j,d);
	}
	REP(i,N){
		rn d = max(abs(ps-p[i])-r[i],0.0L);
		addBiEdge(g,s,i,d);
	}
	REP(i,N){
		rn d = max(abs(pt-p[i])-r[i],0.0L);
		addBiEdge(g,i,t,d);
	}
	addBiEdge(g,s,t,abs(ps-pt));
	vector<Weight> dist;
	vector<int> prev;
	shortestPath(g,s,dist,prev);
	printf("%.10Lf\n",dist[t]);
	return 0;
}
