#include "bits/stdc++.h"

//region Template
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 1000000007;

using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

#define finish(x) cout << x; exit(0);
#define fastIO cin.tie(0); cin.sync_with_stdio(false);

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

//const string USCAO_TAG = "mountains";
void usaco(const string& USACO_TAG) { setIn(USACO_TAG + ".in"); setOut(USACO_TAG + ".out"); }
/*
template<typename... Args>
void print(Args... args) {
	#ifdef LOCAL
	((std::cout << args << " "), ...);
	cout << endl;
	#endif
}
 */
//endregion

/* Notes:
 * Farah </3
 */

const int MAXN = 1e3 + 6;

ld dist(ld x1, ld y1, ld x2, ld y2){
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct q{
	int x, y, r;
};

q a[MAXN];

ld d[MAXN];


vector<vector<pair<int, ld>>> adj;
bool V[MAXN];

int main() {
	#ifdef LOCAL

	setIn("in.txt");
	setOut("out.txt");
	#endif

	int xs, ys, xe, ye;
	cin >> xs >> ys >> xe >> ye;

	a[0] = {xs, ys, 0};
	int n;
	cin >> n;

	a[n + 1] = {xe, ye, 0};
	adj.assign(n + 5, vector<pair<int, ld>>());


	for(int i = 1; i < n + 2; i++){
		d[i] = 1e18;
	}

	for(int i = 0; i < n; i++){
		int x, y, r;
		cin >> x >> y >> r;

		a[i + 1] = {x, y, r};
	}

	for(int i = 0; i < n + 2; i++){
		for(int j = i + 1; j < n + 2; j++){
			ld dis = dist(a[i].x, a[i].y, a[j].x, a[j].y) - (a[i].r + a[j].r);
			adj[i].push_back({j, max((ld)0, dis)});
			adj[j].push_back({i, max((ld)0, dis)});
		}
	}

	d[0] = 0;

	for(int i = 0; i < n + 2; i++){
		int cur_m = -1;
		for(int j = 0; j < n + 2; j++){
			if(!V[j] && (cur_m == -1 || d[j] <= d[cur_m])){
				cur_m = j;
			}
		}

		V[cur_m] = 1;
		for(auto x : adj[cur_m]){
			if(d[cur_m] + x.second < d[x.first]){
				d[x.first] = d[cur_m] + x.second;
			}
		}
	}

	cout << fixed << setprecision(8) << d[n + 1] << endl;
}
