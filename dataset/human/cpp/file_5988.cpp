#include<cstdio>
#include<algorithm>
long long x[100000], v[100000], s[2][100000], t[2][100000];
int main() {
	long long n, c, i, ans;
	scanf("%lld%lld", &n, &c);
	for (i = 0; i < n; i++) scanf("%lld%lld", &x[i], &v[i]);
	s[0][0] = v[0];
	for (i = 1; i < n; i++)s[0][i] = s[0][i - 1] + v[i];
	s[1][n - 1] = v[n - 1];
	for (i = n - 2; i >= 0; i--)s[1][i] = s[1][i + 1] + v[i];
	for (i = 0; i < n; i++) {
		s[0][i] -= x[i];
		s[1][i] -= c - x[i];
		t[0][i] = s[0][i] - x[i];
		t[1][i] = s[1][i] - (c - x[i]);
	}
	t[0][0] = std::max(t[0][0], (long long)0);
	for (i = 1; i < n; i++) t[0][i] = std::max(t[0][i - 1], t[0][i]);
	t[1][n - 1] = std::max(t[1][n - 1], (long long)0);
	for (i = n - 2; i >= 0; i--)t[1][i] = std::max(t[1][i + 1], t[1][i]);
	for (i = 0; i < n - 1; i++) s[0][i] += t[1][i + 1];
	for (i = 1; i < n; i++)s[1][i] += t[0][i - 1];
	std::sort(s[0], s[0] + n);
	std::sort(s[1], s[1] + n);
	if (s[0][n - 1] < 0)s[0][n - 1] = 0;
	printf("%lld", std::max(s[0][n - 1], s[1][n - 1]));
	return 0;
}
