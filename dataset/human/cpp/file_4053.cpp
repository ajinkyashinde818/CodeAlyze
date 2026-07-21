#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
#define SQR(_a) ((_a) * (_a))
typedef long long LL; using namespace std;

int main() {
	LL xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int n;
	cin >> n;
	LL x[n + 2], y[n + 2], r[n + 2];
	x[0] = xs, y[0] = ys, r[0] = 0;
	x[n + 1] = xt, y[n + 1] = yt, r[n + 1] = 0;
	ffor (i, 1, n + 1)
		cin >> x[i] >> y[i] >> r[i];
	n += 2;
	bool done[n];
	SET(done, 0);
	double dist[n];
	FOR (i, n)
		dist[i] = -1.0;
	dist[0] = 0.0;
	while (!done[n - 1]) {
		int v = -1;
		FOR (i, n) {
			if (!done[i])
				if (dist[i] > -0.5)
					if (v == -1 || dist[i] < dist[v])
						v = i;
		}
		done[v] = true;
		FOR (i, n) {
			if (done[i])
				continue;
			double d = sqrt(SQR(x[i] - x[v]) + SQR(y[i] - y[v]));
			d -= (r[v] + r[i]);
			if (d < 0.0)
				d = 0.0;
			if (dist[i] < -0.5 || dist[v] + d < dist[i])
				dist[i] = dist[v] + d;
		}
	}
	cout << std::fixed;
	cout << std::setprecision(10) << dist[n - 1] << endl;
	return 0;
}
