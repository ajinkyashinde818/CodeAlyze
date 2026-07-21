#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxN = 1e5 + 5;
ll s1[maxN], s2[maxN], s3[maxN], s4[maxN], v[maxN], C, x[maxN];
int N;

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%lld", &N, &C); x[N + 1] = C;
	for(int i = 1; i <= N; ++i) scanf("%lld%lld", &x[i], &v[i]);
	ll ans = 0;
	for(int i = 1; i <= N; ++i) {
		s1[i] = s1[i - 1] + v[i] - (x[i] - x[i - 1]);
		ans = max(ans, s1[i]);
		s2[i] = s2[i - 1] + v[i] - 2 * (x[i] - x[i - 1]); 
	}
	for(int i = N; i >= 1; --i) {
		s3[i] = s3[i + 1] + v[i] - (x[i + 1] - x[i]);
		ans = max(ans, s3[i]);
		s4[i] = s4[i + 1] + v[i] - 2 * (x[i + 1] - x[i]);
	}
	for(int i = 1; i <= N; ++i) s2[i] = max(s2[i - 1], s2[i]);
	for(int i = N; i >= 1; --i) s4[i] = max(s4[i + 1], s4[i]);
	for(int i = 1; i <= N; ++i) {
		ans = max(ans, s1[i] + s4[i + 1]);
		ans = max(ans, s3[i] + s2[i - 1]);
	}
	cout << ans << endl;
	return 0;
}
