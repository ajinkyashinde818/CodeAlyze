#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#include <iomanip>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing
using PII = pair<double, int>;
int main() {
	int xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int n;
	cin >> n;
	vector <tuple<int, int, int>> A(n + 2);
	for (int i = 1; i <= n; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		A[i] = make_tuple(x, y, r);
	}
	A[0] = make_tuple(xs, ys, 0);
	A[n + 1] = make_tuple(xt, yt, 0);
	auto calcDist = [&] (int i, int j) {
		ll x1, y1, r1;
		tie(x1, y1, r1) = A[i];
		ll x2, y2, r2;
		tie(x2, y2, r2) = A[j];
		return max(0.0, double(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) - (r1 + r2))); 
	};
	// dijkstra
	vector<double> dist(n + 2, INF);
	set <PII> st;
	st.insert({0, 0});
	dist[0] = 0;
	while(!st.empty()) {
		int x = st.begin()->ss;
		st.erase(st.begin());
		for (int i = 1; i <= n + 1; i++) {
			double distxi = calcDist(x, i);
			if (dist[x] + distxi < dist[i]) {
				st.erase({dist[i], i});
				dist[i] = dist[x] + distxi;
				st.insert({dist[i], i});
			}
		}
	}
	printf("%.10lf", dist[n + 1]);
}
