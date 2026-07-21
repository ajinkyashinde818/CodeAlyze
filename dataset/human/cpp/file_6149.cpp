#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


typedef long long i64;
const int inf = (int)1.05e9;


int main()
{
	int n;
	i64 c;
	vector<i64> xs;
	vector<i64> vs;

	scanf("%d%lld", &n, &c);
	xs.resize(n);
	vs.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%lld%lld", &xs[i], &vs[i]);

	vector<i64> cw_sum(n), ccw_sum(n);
	vector<i64> cw_sum_max(n), ccw_sum_max(n);

	cw_sum[0] = vs[0] - xs[0];
	cw_sum_max[0] = cw_sum[0];
	for(int i = 1; i < n; ++i) {
		cw_sum[i] = cw_sum[i - 1] + (vs[i] - (xs[i] - xs[i - 1]));
		cw_sum_max[i] = max(cw_sum_max[i - 1], cw_sum[i]);
	}

	ccw_sum[n - 1] = vs[n - 1] - (c - xs[n - 1]);
	ccw_sum_max[n - 1] = ccw_sum[n - 1];
	for(int i = n - 2; i >= 0; --i) {
		ccw_sum[i] = ccw_sum[i + 1] + (vs[i] - (xs[i + 1] - xs[i]));
		ccw_sum_max[i] = max(ccw_sum_max[i + 1], ccw_sum[i]);
	}

	i64 ans = 0;

	for(int i = 0; i < n; ++i) {
		i64 x = cw_sum[i];
		i64 y = (i + 1 < n) ? ccw_sum_max[i + 1] : 0LL;
		i64 t = x + max(y - xs[i], 0LL);
		ans = max(ans, t);
	}

	for(int i = n - 1; i >= 0; --i) {
		i64 x = ccw_sum[i];
		i64 y = (i - 1 >= 0) ? cw_sum_max[i - 1] : 0LL;
		i64 t = x + max(y - (c - xs[i]), 0LL);
		ans = max(ans, t);
	}

	printf("%lld\n", ans);

	return 0;
}

/* waffle */
