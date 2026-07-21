#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const pii Dir[8] = { //?????????
	{ 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 },
	{ 1,1 },{ 1,-1 },{ -1,-1 },{ -1,1 }
};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*) array, (T*) (array + N), val);
}

////テンプレ////
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> Pt;//点
namespace std {
	bool operator < (const Pt& a, const Pt& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
double cross(const Pt& a, const Pt& b) {
	return imag(conj(a)*b);
}
double dot(const Pt& a, const Pt& b) {
	return real(conj(a)*b);
}

struct Ln : public vector<Pt> {//線
	Ln(const Pt &a, const Pt &b) {
		push_back(a); push_back(b);
	}
};

typedef vector<Pt> Pol;//多角形

struct Cir {//円
	Pt p; double r;
	Cir(const Pt &p, double r) : p(p), r(r) { }
};
double distancePP(const Pt &p, const Pt &q) {
	return hypot(p.real() - q.real(), p.imag() - q.imag());
}
double distanceCC(const Cir &p, const Cir &q) {
	return distancePP(p.p,q.p) - p.r - q.r;
}
bool intersectCC(const Cir &c1, const Cir &c2) {
	return distanceCC(c1,c2) <= 0;
}

signed main() {
	pair<double,double> now, tar;
	int n;

	scanf("%lf %lf %\lf %lf", &now.first, &now.second, &tar.first, &tar.second);

	scanf("%d", &n);

	vector<Cir> bar;
	bar.push_back({ {now.first,now.second},0 });
	REP(i, n) {
		double x, y, r;
		scanf("%lf %lf %lf", &x, &y, &r);
		bar.push_back({ { x,y }, r });
	}
	bar.push_back({ { tar.first,tar.second },0 });
	n += 2;
	vector < vector < pair<int, double> >> graph(n);//to,cost

	REP(i, n) {
		rep(j, i + 1, n) {
			if (intersectCC(bar[i], bar[j])) {
				graph[i].push_back({ j,0 });
				graph[j].push_back({ i,0 });
			}
			else {
				graph[i].push_back({ j,distanceCC(bar[i],bar[j]) });
				graph[j].push_back({ i,distanceCC(bar[i],bar[j]) });
			}
		}
	}

	priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>>> que;//num,cost;
	vector<double> cost(n,-1);
	que.push({ 0,0 });
	while (que.size()) {
		pair<double,int> cur = que.top();
		que.pop();

		if (cost[cur.second] != -1)
			continue;
		cost[cur.second] = cur.first;
		REP(i, graph[cur.second].size()) {
			que.push({ cur.first + graph[cur.second][i].second,graph[cur.second][i].first });
		}

	}
	printf("%.12lf\n", cost[n-1]);
	return 0;
}
