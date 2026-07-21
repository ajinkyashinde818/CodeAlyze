#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
//#include<boost/multiprecision/cpp_int.hpp>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define EACH(i, a) for (auto i: a)
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define intmax (std::numeric_limits<int64_t>::max() / 4)
#define doublemax (std::numeric_limits<double>::max() / 4)
using namespace std;
//typedef boost::multiprecision::cpp_int bigint;
const double EPS = 1e-9;
const double PI = acos(-1.0);



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	double xstart, ystart, xend, yend;
	cin >> xstart >> ystart >> xend >> yend;
	int N;
	cin >> N;
	vector<array<double, 3>>bar(N+2);
	rep(i, N) {
		cin >> bar[i][0] >> bar[i][1] >> bar[i][2];
	}
	bar[N] = { xstart,ystart,0.0 };
	bar[N+1] = { xend,yend,0.0 };

	//graph[i][j]:=バリアiの中心からバリアjの中心に行くためのコスト
	vector<vector<double>>graph(N+2, vector<double>(N+2));
	rep(i, N + 2)REP(j, i + 1, N + 2) {
		double dx = bar[i][0] - bar[j][0];
		double dy = bar[i][1] - bar[j][1];
		double dist = sqrt(dx*dx + dy*dy);
		double gain = bar[i][2] + bar[j][2];
		graph[i][j] = max(0.0, dist - gain);
		graph[j][i] = graph[i][j];
	}

	typedef pair<double, int>p;
	vector<int>searched(N + 2, 0);
	priority_queue<p, vector<p>, greater<p>>D;
	D.push(make_pair(0.0, N));
	while (!D.empty()) {
		auto x = D.top(); D.pop();
		double dist = x.first;
		int pos = x.second;
		if (searched[pos]++)continue;
		if (pos == N + 1) {
			cout << setprecision(20)<<dist << endl;
			return 0;
		}
		rep(i, N + 2)if (searched[i] == 0) {
			D.push({ dist + graph[pos][i],i });
		}
	}


	return 0;
}
