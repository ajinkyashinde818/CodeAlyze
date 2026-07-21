#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
int main() {
	int N;
	int a[200010];
	cin >> N;
	ll sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	ll ans = 1e10;
	ll sum2 = 0;
	for (int i = 0; i < N-1; ++i) {
			sum2 += a[i];
			ll A = (sum - sum2) - sum2;
			if (A < 0)A -= 2 * A;
			ans = min(ans, A);
	}
	cout << ans << endl;
	return 0;
}
