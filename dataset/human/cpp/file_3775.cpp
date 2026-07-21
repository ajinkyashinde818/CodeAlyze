#include <bits/stdc++.h>
using namespace std;

int main() {
	long long xs, ys, xt, yt, N;
	cin >> xs >> ys >> xt >> yt >> N;

	N += 2;
	vector<long double> x(N), y(N), r(N);
	x[0] = xs;
	y[0] = ys;
	x[1] = xt;
	y[1] = yt;

	for(int i = 2; i < N; ++i) {
		cin >> x[i] >> y[i] >> r[i];
	}

	priority_queue<pair<long double, int>> pq;
	pq.push({0, 0});

	vector<bool> visited(N);
	vector<long double> distances(N);

	while(!pq.empty()) {
		long double d; int i;
		tie(d, i) = pq.top(); d = -d;
		pq.pop();

		if(visited[i]) continue;

		visited[i] = true;
		distances[i] = d;

		for(int j = 0; j < N; ++j) {
			if(visited[j]) continue;

			pq.push({
				-(d + max(0.0l, hypot(x[j] - x[i], y[j] - y[i]) - r[i] - r[j])),
				j,
			});
		}
	}

	printf("%.10lf", (double)distances[1]);

	return 0;
}
