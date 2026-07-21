#include <stdio.h>
#include <algorithm>

#define LIM_N 100002

char str[LIM_N];

int N;
char S[LIM_N];

const long long DIV = 1000000007;
long long count[26];
long long ans;

void receive_input() {
	fgets(str, sizeof(str), stdin);
	sscanf(str, "%d", &N);

	fgets(str, sizeof(str), stdin);
	sscanf(str, "%s", S);
}

void initialize() {
	// nop
}

void swap(long long &a, long long &b) {
	long long temp = a;
	a = b;
	b = temp;
}

long long mod_inv(long long a) {
	long long b = DIV, u = 1, v = 0;
	while (b) {
		long long t = a / b;

		a -= t * b;
		swap(a, b);

		u -= t * v;
		swap(u, v);
	}
	u %= DIV;
	if (u < 0) u += DIV;
	return u;
}

long long mod_div(long long a, long long b) {
	long long result = a * mod_inv(b);
	result %= DIV;
	return result;
}

void solve() {

	for (size_t i = 0; S[i]; i++) {
		int c = S[i] - 'a';
		ans += 1;

		ans = mod_div(ans, count[c]+1);
		count[c] += 1;
		ans *= count[c]+1;

		ans -= 1;
		ans %= DIV;
	}
}

int main(void) {
	receive_input();
	initialize();

	solve();

	printf("%lld\n", ans);

	return 0;
}
