#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int n, c;
int x[100000];
int v[100000];
int rv[200010];

int solve1() {
	int r;
	int fl = 0, fr, ret = 0;
	for (r = 1; r < n; r++) {
		fl = max(fl, rv[n + r] - x[r - 1]);
		fr = -rv[r] - 2 * (c - x[r]);
		ret = max(ret, fl + fr);
	}
	return ret;
}

int solve2() {
	int r;
	int fl = 0, fr, ret = 0;
	for (r = 1; r < n; r++) {
		fl = max(fl, rv[n + r] - 2 * x[r - 1]);
		fr = -rv[r] - (c - x[r]);
		//cout << "res2 : " << "r = " << r << ", fl = " << fl << ", fr = " << fr << endl;
		ret = max(ret, fl + fr);
	}
	return ret;
}

int solve3() {
	int l, ret = 0;
	for (l = 0; l < n; l++) {
		ret = max(ret, rv[l + 1] - x[l]);
	}
	return ret;
}

int solve4() {
	int r, ret = 0;
	for (r = 0; r < n; r++) {
		ret = max(ret, rv[n] - rv[r] - (c - x[r]));
	}
	return ret;
}

signed main() {
	int i;
	
	cin >> n >> c;
	rep(i, n) cin >> x[i] >> v[i];
	rep(i, n) rv[i + 1] = rv[i] + v[i];
	rep(i, n) rv[i + n + 1] = rv[i + n] + v[i];
	//rep(i, 2 * n + 1) cout << rv[i] << " "; cout << endl;
	int res1 = solve1(); //cout << "res1 = " << res1 << endl;
	int res2 = solve2(); //cout << "res2 = " << res2 << endl;
	int res3 = solve3(); //cout << "res3 = " << res3 << endl;
	int res4 = solve4(); //cout << "res4 = " << res4 << endl;
	
	cout << max(res1, max(res2, max(res3, res4))) << endl;
	return 0;
}
