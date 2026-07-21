#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <climits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <set>
#include <array>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define VS vector<string>
#define VI vector<ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define pcc pair<char,char>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define eps 1e-14
#define FST first
#define SEC second
#define SETUP cin.tie(0), ios::sync_with_stdio(false), cout << setprecision(15)

namespace {
	struct input_returnner {
		ll N; input_returnner(ll N_ = 0) :N(N_) {}
		template<typename T> operator vector<T>() const { vector<T> res(N); for (auto &a : res) cin >> a; return std::move(res); }
		template<typename T> operator T() const { T res; cin >> res; return res; }
		template<typename T> T operator - (T right) { return T(input_returnner()) - right; }
		template<typename T> T operator + (T right) { return T(input_returnner()) + right; }
		template<typename T> T operator * (T right) { return T(input_returnner()) * right; }
		template<typename T> T operator / (T right) { return T(input_returnner()) / right; }
		template<typename T> T operator << (T right) { return T(input_returnner()) << right; }
		template<typename T> T operator >> (T right) { return T(input_returnner()) >> right; }
	};
	template<typename T> input_returnner in() { return in<T>(); }
	input_returnner in() { return input_returnner(); }
	input_returnner in(ll N) { return std::move(input_returnner(N)); }
}

ll MOD = 1e9 + 7;

void solve();

signed main() {
	SETUP;
	solve();
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}

#define int ll

double dist(const tuple<int, int, int>& left, const tuple<int ,int ,int>& right) {
	int lx, ly, lr;
	std::tie(lx, ly, lr) = left;
	int rx, ry, rr;
	std::tie(rx, ry, rr) = right;
	return max(std::sqrt((lx - rx)*(lx - rx) + (ly - ry)*(ly - ry)) - lr - rr, 0.0);
}

void solve() {
	int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
	int N; cin >> N;
	vector<vector<pair<double, int>> > Graph(N+2); //[node] = {(cost, to)}
	vector<tuple<int, int, int>> Node; //x,y,r
	REP(i, N) {
		int x, y, r; cin >> x >> y >> r;
		Node.emplace_back(x, y, r);
	}
	REP(i, N) {
		REP(j, N) if(i < j){
			double d = dist(Node[i], Node[j]);
			Graph[i].emplace_back(d, j);
			Graph[j].emplace_back(d, i);
		}
	}
	REP(i, N) {
		double d = dist(make_tuple(xs,ys,0), Node[i]);
		Graph[N].emplace_back(d, i);
	}
	REP(i, N) {
		double d = dist(make_tuple(xt,yt,0), Node[i]);
		Graph[i].emplace_back(d, N+1);
	}
	{
		double d = dist(make_tuple(xs, ys, 0), make_tuple(xt, yt, 0));
		Graph[N].emplace_back(d, N+1);
	}

	priority_queue<pair<double ,int>, vector<pair<double, int>>, greater<pair<double, int>> > que; // cost index
	vector<bool> visited(Graph.size());
	vector<double> dist(Graph.size(), -1);
	que.emplace(0, N);
	dist[N] = 0;
	while (not que.empty()) {
		auto cur = que.top(); que.pop();
		if (cur.second == N+1) {
			cout << dist[cur.second] << endl;
			return;
		}
		if (visited[cur.second]) continue;
		visited[cur.second] = true;
		for (auto &a : Graph[cur.second]) {
			int to = a.second;
			double c = a.first;
			if (dist[to] < 0 or dist[to] > dist[cur.second] + c) {
				dist[to] = dist[cur.second] + c;
				que.emplace(dist[cur.second] + c, to);
			}
		}
	}
}
