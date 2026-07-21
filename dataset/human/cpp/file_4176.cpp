#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <ynt> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 1019;
double d[N][N], dmin[N];
int n, k, m, a, b, x[N], y[N], r[N], use[N];

double dist(int a, int b) {
	long long X = x[a] - x[b];
	long long Y = y[a] - y[b];
	return sqrt(X * X + Y * Y);
}

double getd(int i, int j) {
	return max(0., dist(i, j) - r[i] - r[j]);
}

double dijkstra() {
	for(int i = 1; i <= n; i++) dmin[i] = 1e18;
	dmin[0] = 0;
	// use[0] = 0;
	
	for(int i = 0; i <= n; i++) {
		
		double minn = 1e17;
		int k = -1;

		for(int i = 0; i <= n; i++)
			if(!use[i] && dmin[i] < minn) {
				k = i;
				minn = dmin[i];
			}

		use[k] = 1;
		for(int i = 0; i <= n; i++)
			if(dmin[i] > dmin[k] + d[i][k])
				dmin[i] = dmin[k] + d[i][k];
	}
	return dmin[1];
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> x[0] >> y[0] >> x[1] >> y[1];
	r[0] = r[1] = 0;
	cin >> n;
	n++;
	for(int i = 2; i <= n; i++)
		cin >> x[i] >> y[i] >> r[i];

	for(int i = 0; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			d[i][j] = d[j][i] = getd(i, j);

	cout << fixed << setprecision(10) << dijkstra() << '\n';
}
