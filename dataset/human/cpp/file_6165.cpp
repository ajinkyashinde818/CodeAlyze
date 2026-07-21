#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	int64_t C;
	int64_t X[100005], V[100005];
	int64_t ans;

	cin >> N >> C;
	for ( int i = 0; i < N; i++ ) {
		cin >> X[i] >> V[i];
	}
	
	function < int64_t() > calc = [&]
	{
		int64_t now_max = 0, sum = 0;
		int64_t maxv[100005];
		int64_t ret;
		for ( int i = 0; i < N; i++ ) {
			sum += V[i];
			if ( now_max < sum - X[i] ) {
				now_max = sum - X[i];
			}
			maxv[i] = now_max;
		}
		ret = now_max;
		sum = 0;
		for ( int i = N - 1; i > 0; i-- ) {
			sum += V[i];
			ret = max(ret, maxv[i - 1] + sum - (C - X[i]) * 2);
		}
		return (ret);	
	};
	
	ans = calc();
	for ( int i = 0; i < N; i++ ) {
		X[i] = C - X[i];
	}

	reverse(X, X + N);
	reverse(V, V + N);
	
	ans = max(ans, calc());

	cout << ans << endl;

	return (0);
}
