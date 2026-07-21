#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

#define FOR(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)

using namespace std;

const double INF = 1e50;


int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	vector<long long> x(n + 2), y(n + 2), r(n + 2);
	x[0] = x1, x[n + 1] = x2;
	y[0] = y1, y[n + 1] = y2;
	r[0] = 0, r[n + 1] = 0;

	IFOR(i, 1, n) {
		cin >> x[i] >> y[i] >> r[i];
	}
	vector<vector<double>> dist(n + 2, vector<double>(n + 2));
	FOR(i, 0, n + 2) {
		FOR(j, 0, n + 2) {
			dist[i][j] = max(0.0, sqrt((y[j] - y[i])*(y[j] - y[i]) + (x[j] - x[i]) * (x[j] - x[i])) - r[i] - r[j]);
		}
	}

	int pos = 0;
	priority_queue < pair<double, int>, vector < pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push(make_pair(0.0, 0));

	vector<double> mindist(n + 2, INF);
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		double cost = t.first;
		int node = t.second;
		if (mindist[node] < INF - 1)
			continue;
		mindist[node] = cost;
		if (node == n + 1)
			break;
		FOR(i, 0, n + 2) {
			if (i != node && dist[node][i] < INF - 1 && mindist[i] > INF/10.0) {
				pq.push(make_pair(cost + dist[node][i], i));
			}
		}
	}

	printf("%.14f\n", mindist[n + 1]);
	return 0;
}
