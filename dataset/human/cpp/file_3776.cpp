#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, x[1002], y[1002];
double r[1002], mat[1002][1002], shortest[1002];
bool used[1002];

void set() {

	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			double p1 = pow(x[i] - x[j], 2);
			double p2 = pow(y[i] - y[j], 2);
			mat[i][j] = max((double)0, sqrt(p1 + p2)-(r[i]+r[j]));
		}
	}

}

double dijkstra() {
	for (int i = 0; i < n + 2; i++) {
		shortest[i] = -1;
	}
	shortest[0] = 0;

	while (true) {
		int v = -1;
		for (int i = 0; i < n + 2; i++) {
			if (!used[i] && shortest[i] != -1 && (v == -1 || shortest[v] > shortest[i])) {
				v = i;
			}
		}
		if (v == -1)break;
		used[v] = true;

		for (int i = 0; i < n + 2; i++) {
			if (shortest[i] == -1) {
				shortest[i] = shortest[v] + mat[v][i];
			}
			else {
				shortest[i] = min(shortest[i], shortest[v] + mat[v][i]);
			}
		}
	}

	return shortest[1];
}

int main() {
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
	for (int i = 2; i < n + 2; i++) {
		cin >> x[i] >> y[i] >> r[i];
	}
	set();

	cout << fixed << setprecision(10) << dijkstra() << endl;
}
