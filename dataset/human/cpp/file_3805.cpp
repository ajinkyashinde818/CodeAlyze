// practice with Dukkha
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 1000;
const double INF = 4e9;

int xx[N + 2], yy[N + 2], rr[N + 2];
double dd[N + 2];
bool used[N + 2];

int main() {
	int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
	int n; cin >> n;
	xx[0] = xs, yy[0] = ys;
	for (int i = 1; i <= n; i++)
		cin >> xx[i] >> yy[i] >> rr[i];
	xx[n + 1] = xt, yy[n + 1] = yt;
	n += 2;
	fill(dd, dd + n, INF);
	dd[0] = 0;
	while (true) {
		int i = -1;
		for (int j = 0; j < n; j++)
			if (!used[j] && (i == -1 || dd[i] > dd[j]))
				i = j;
		if (i == -1)
			break;
		used[i] = true;
		for (int j = 0; j < n; j++)
			if (!used[j])
				dd[j] = min(dd[j], dd[i] + max(hypot(xx[i] - xx[j], yy[i] - yy[j]) - rr[i] - rr[j], 0.0));
	}
	printf("%.10f\n", dd[n - 1]);
	return 0;
}
