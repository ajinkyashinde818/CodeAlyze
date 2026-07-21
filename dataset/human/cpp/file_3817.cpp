#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

ll xs, ys, xt, yt;
ll x[1200];
ll y[1200];
int en[1200];
ld dd[1200];
ld ed[1200][1200];
ld r[1200];
int n;


int main() {
	cin >> xs >> ys >> xt >> yt;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i] >> r[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			ld d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			if (d > r[i] + r[j])
				ed[i][j] = d - r[i] - r[j];
		}
	for (int i = 0; i < n; ++i) {
		ld d = sqrt((x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys));
		if (d > r[i])
			ed[i][n] = ed[n][i] = d - r[i];
	}
	for (int i = 0; i < n; ++i) {
		ld d = sqrt((x[i] - xt) * (x[i] - xt) + (y[i] - yt) * (y[i] - yt));
		if (d > r[i])
			ed[i][n + 1] = ed[n + 1][i] = d - r[i];
	}
	ed[n][n + 1] = ed[n + 1][n] = sqrt((xs - xt) * (xs - xt) + (ys - yt) * (ys - yt));
	for (int i = 0; i <= n + 1; ++i)
		dd[i] = 1e10;
	dd[n] = 0;
	for (int i = 0; i <= n + 1; ++i) {
		int mn = -1;
		for (int j = 0; j <= n + 1; ++j)
			if (!en[j] && (mn == -1 || dd[mn] > dd[j]))
				mn = j;
		en[mn] = 1;
		for (int j = 0; j <= n + 1; ++j)
			dd[j] = min(dd[j], dd[mn] + ed[mn][j]);
	}
	printf("%.9Lf\n", dd[n + 1]);
	return 0;
}
