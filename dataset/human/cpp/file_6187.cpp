#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	ll c;
	cin >> n >> c;
	vector<ll> d(n), v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &d[i]);
		scanf("%lld", &v[i]);
	}
	ll res = 0;
	vector<ll> mxA(n), mxB(n);
	ll total = 0;
	for (int i = 0; i < n; ++i) {
		total += v[i];
		mxA[i] = total - d[i];
		if (i)
			mxA[i] = max(mxA[i], mxA[i - 1]);
		res = max(res, mxA[i]);
	}
	total = 0;
	for (int i = n - 1; i >= 0; --i) {
		total += v[i];
		mxB[i] = total - (c - d[i]);
		if (i + 1<n)
			mxB[i] = max(mxB[i], mxB[i + 1]);
		res = max(res, mxB[i]);
	}
	total = 0;
	for (int i = 0; i < n; ++i) {
		total += v[i];
		ll cur = total - d[i] * 2;
		if (i + 1 < n)
			cur += mxB[i + 1];
		res = max(res, cur);
	}
	total = 0;
	for (int i = n - 1; i >= 0; --i) {
		total += v[i];
		ll cur = total - (c - d[i]) * 2;
		if (i)
			cur += mxA[i - 1];
		res = max(res, cur);
	}
	cout << res << endl;
	return 0;
}
