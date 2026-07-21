#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fst first
#define snd second
const ll mod = 1000000007;
const ll INF = (1LL << 59);
const double dINF = 1000000000000000000.0;

struct Bar {
	ll x, y, r;
};

Bar p[1010];

int main(){
	cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
	p[0].r = p[1].r = 0;

	double d[1010];
	bool used[1010];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i + 2].x >> p[i + 2].y >> p[i+2].r;
	}
	n += 2;
	for (int i = 1; i < n; i++) {
		d[i] = dINF;
		used[i] = false;
	}
	d[0] = 0.0; used[0] = false;
	while (1) {
		double min_=dINF;
		for (int i = 0; i < n; i++) {
			if (used[i])continue;
			min_ = min(min_, d[i]);
		}
		if (min_ == dINF)break;
		for (int i = 0; i < n; i++) {
			if (d[i] == min_) {
				for (int j = 0; j < n; j++) {
					if (used[j])continue;
					d[j] = min(d[j], d[i] + max(0.0, sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y)) - p[i].r - p[j].r));
				}
				used[i] = true;
			}
		}
	}
	printf("%.15lf\n", d[1]);
	return 0;
}
