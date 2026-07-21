#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int xs, ys, xt, yt, n;
	int x[1002], y[1002], r[1002];
	cin >> xs >> ys >> xt >> yt >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y [i] >> r[i];
	}
	x[n + 1] = xs; y[n + 1] = ys; r[n + 1] = 0;
	x[n] = xt; y[n] = yt; r[n] = 0;

	static double dist[1002][1002];
	for (int i = 0; i < n + 2; i++) {
		for (int j = i; j < n + 2; j++) {
			double dx = x[i] - x[j];
			double dy = y[i] - y[j];
			dist[i][j] = dist[j][i] = max(0.0, sqrt(dx * dx + dy * dy) - r[i] - r[j]);
		}
	}

	double cost[1002];
	for (int i = 0; i < n + 1; i++) {
		cost[i] = dist[n + 1][i];
	}

	bool b[1002] = {};
	for (int i = 0; i < n + 1; i++) {
		b[i] = true;
	}
	for (bool l = true; l; ) {
		l = false;
		for(int m = 0; m < n; m++) {
			if (b[m]) {
				b[m] = false;
				for (int i = 0; i < n + 1; i++) {
					if (cost[m] + dist[m][i] < cost[i]) {
						cost[i] = cost[m] + dist[m][i];
						b[i] = true;
						l = true;
					}
				}
			}
		}
	}
	cout << fixed << setprecision(10) << cost[n] << endl;
	return 0;
}
