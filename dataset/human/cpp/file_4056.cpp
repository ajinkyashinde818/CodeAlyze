#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;


int main() {
	ios::sync_with_stdio(false);
	long double sx, sy, gx, gy;
	long double x[2000] = {};
	long double y[2000] = {};
	long double r[2000] = {};
	long double dis[2000] = {};
	cin >> sx >> sy >> gx >> gy;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x[i] >> y[i] >> r[i];
	}
	x[0] = sx;
	y[0] = sy;
	r[0] = 0;
	x[N+1] = gx;
	y[N+1] = gy;
	r[N+1] = 0;
	for (int i = 1; i <= N+1; i++) {
		dis[i] = 10000000000;
	}
	priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>>PQ;
	PQ.push({ 0,0 });
	while (!PQ.empty()) {
		long double c = PQ.top().first;
		int cn = PQ.top().second;
		PQ.pop();
		if (dis[cn] < c)continue;
		for (int i = 1; i <= N + 1; i++) {
			if (dis[i] > dis[cn] + max((long double)0, sqrt((x[i] - x[cn])*(x[i] - x[cn]) + (y[i] - y[cn])*(y[i] - y[cn])) - r[i] - r[cn])) {
				dis[i] = dis[cn] + max((long double)0, sqrt((x[i] - x[cn])*(x[i] - x[cn]) + (y[i] - y[cn])*(y[i] - y[cn])) - r[i] - r[cn]);
				PQ.push({ dis[i], i });
			}
		}
	}
	cout << setprecision(15) << dis[N + 1] << endl;
	return 0;
}
