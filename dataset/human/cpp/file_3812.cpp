#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "unordered_set"
#include "stack"
#include "tuple"

#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<int,int>

typedef long long ll;
using namespace std;

int n;

double x[1002], y[1002], r[1002], d[1002][1002],g[1002];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>q;

int main() {
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
	r[0] = r[1] = 0;

	rep(n) {
		cin >> x[i + 2] >> y[i + 2] >> r[i + 2];
	}
	rep(n + 2) {
		REP(n+2, j) {
			d[i][j] = max(sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - r[i] - r[j], (double)0);
		}
	}
	rep(n + 2)
		g[i] = -1;
	g[0] = 0;
	for (int i = 1; i < n + 2; ++i) {
		q.push(mkp(d[0][i], i));
	}
	while (!q.empty()) {
		double qfst = q.top().first;
		int qsnd = q.top().second;
		q.pop();
		if (g[qsnd] == -1) {
			g[qsnd] = qfst;
			rep(n + 2) {
				if (g[i] == -1) {
					q.push(mkp(qfst + d[qsnd][i], i));
				}
			}
		}
	}
	printf("%.10f", g[1]);
	return 0;
}
