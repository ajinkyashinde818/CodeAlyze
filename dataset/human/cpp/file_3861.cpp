#include<iostream>
#include<math.h>
using namespace std;

long double cost[1002][1002];
long double d[1002];
bool used[1002];

int main() {

	long double d[1002];
	long double x[1002], y[1002], r[1002];
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	int i, n, j;
	cin >> n;
	r[0] = 0; r[1] = 0;
	for (i = 0; i < n; i++) {
		cin >> x[i + 2] >> y[i + 2] >> r[i + 2];
	}
	for (i = 0; i < n + 2; i++) {
		for (j = 0; j < n + 2; j++) {
			cost[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j];
			if (cost[i][j] < 0)cost[i][j] = 0;
		}
	}
	long double INF = 3000000000;

	for (i = 0; i <= n + 1; i++) {
		d[i] = INF;
		used[i] = false;
	}
	d[0] = 0;
	while (true) {
		int v = -1;

		for (int u = 0; u < n + 2; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v]))v = u;
		}
		if (v == -1)break;
		used[v] = true;
		for (int u = 0; u < n + 2; u++) {
			if (d[u] > d[v] + cost[v][u]) {
				d[u] = d[v] + cost[v][u];
			}
		}
	}

	printf("%.10Lf\n",d[1]);
	return 0;

	/*int n, x;
	cin >> n >> x;
	long long int a[100001];
	int i;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long int counter = 0;
	for (i = 1; i <= n; i++) {
		if (a[i] + a[i - 1] > x) {
			//cout << i << endl;
			counter = counter + (a[i] + a[i - 1] - x);
			a[i] = a[i] - (a[i] + a[i - 1] - x);
			//cout << a[i] << endl;a
			
		}
	}
	cout << counter << endl;
	return 0;*/
}
