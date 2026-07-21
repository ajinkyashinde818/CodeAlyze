#include <stdio.h>

int main()
{
	int i, A, B, Q;
	long long s[100002], t[100002], x[100001];
	scanf("%d %d %d", &A, &B, &Q);
	for (i = 1; i <= A; i++) scanf("%lld", &(s[i]));
	for (i = 1; i <= B; i++) scanf("%lld", &(t[i]));
	for (i = 1; i <= Q; i++) scanf("%lld", &(x[i]));
	s[A+1] = (long long)1 << 60;
	s[0] = -s[A+1];
	t[B+1] = s[A+1];
	t[0] = -s[A+1];
	
	int l[2], r[2], m;
	long long ans;
	for (i = 1; i <= Q; i++) {
		l[0] = 0;
		r[0] = A + 1;
		while (r[0] - l[0] > 1) {
			m = (r[0] + l[0]) / 2;
			if (s[m] < x[i]) l[0] = m;
			else r[0] = m;
		}
		
		l[1] = 0;
		r[1] = B + 1;
		while (r[1] - l[1] > 1) {
			m = (r[1] + l[1]) / 2;
			if (t[m] < x[i]) l[1] = m;
			else r[1] = m;
		}
		
		ans = x[i] - ((s[l[0]] < t[l[1]])? s[l[0]]: t[l[1]]);
		if (((s[r[0]] < t[r[1]])? t[r[1]]: s[r[0]]) - x[i] < ans) ans = ((s[r[0]] < t[r[1]])? t[r[1]]: s[r[0]]) - x[i];
		if (s[r[0]] - t[l[1]] + s[r[0]] - x[i] < ans) ans = s[r[0]] - t[l[1]] + s[r[0]] - x[i];
		if (s[r[0]] - t[l[1]] + x[i] - t[l[1]] < ans) ans = s[r[0]] - t[l[1]] + x[i] - t[l[1]];
		if (t[r[1]] - s[l[0]] + t[r[1]] - x[i] < ans) ans = t[r[1]] - s[l[0]] + t[r[1]] - x[i];
		if (t[r[1]] - s[l[0]] + x[i] - s[l[0]] < ans) ans = t[r[1]] - s[l[0]] + x[i] - s[l[0]];
		printf("%lld\n", ans);
	}
	fflush(stdout);
	return 0;
}
