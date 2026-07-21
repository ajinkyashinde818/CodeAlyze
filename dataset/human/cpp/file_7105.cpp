#include <stdio.h>
#include <algorithm>
int n, x;
long long a[200001];
long long b[200001];
long long z[200000];
long long u[200000];
long long v[200000];
int l, r, f, s, t;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x]++;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		b[x]++;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] + b[i] > n) {
			printf("No\n");
			return 0;
		}
		z[i - 1] = (a[i] + b[i]) * 1000000 + i;
	}
	printf("Yes\n");
	std::sort(z, z + n);
	r = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		x = z[i] % 1000000;
		if (f) {
			for (int j = 0; j < a[x]; j++) {
				u[l] = x;
				l++;
			}
			for (int j = 0; j < b[x]; j++) {
				v[r] = x;
				r--;
			}
		}
		else {
			if (a[x] + b[x] <= r - l + 1) {
				for (int j = 0; j < a[x]; j++) {
					u[l] = x;
					l++;
				}
				for (int j = 0; j < b[x]; j++) {
					v[r] = x;
					r--;
				}
			}
			else {
				t = b[x] - l;
				s = a[x] - (n - 1 - r);
				if (s < 0)s = 0;
				if (t < 0)t = 0;
				if (s + t < r - l + 1) {
					if (a[x] >= r - l + 1 - t)s = r - l + 1 - t;
					else {
						s = a[x];
						t = r - l + 1 - s;
					}
				}
				for (int j = 0; j < s; j++) {
					u[l] = x;
					l++;
				}
				for (int j = 0; j < t; j++) {
					v[r] = x;
					r--;
				}
				for (int j = 0; j < a[x] - s; j++) {
					u[n - 1 - j] = x;
				}
				for (int j = 0; j < b[x] - t; j++) {
					v[j] = x;
				}
				f = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		z[i] = u[i] * 1000000 + v[i];
	}
	std::sort(z, z + n);
	for (int i = 0; i < n; i++) {
		if (i < n - 1)printf("%lld ", z[i] % 1000000);
		else printf("%lld\n", z[i] % 1000000);
	}
}
