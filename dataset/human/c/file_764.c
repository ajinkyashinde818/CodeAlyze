#include <stdio.h>

#define MOD_BY 1000000007

int add(int a, int b) {
	return a + b - (a + b >= MOD_BY ? MOD_BY : 0);
}

int sub(int a, int b) {
	return b == 0 ? a : add(a, MOD_BY - b);
}

int mul(int a, int b) {
	int r = 0;
	while (b > 0) {
		if (b & 1) r = add(r, a);
		a = add(a, a);
		b >>= 1;
	}
	return r;
}

int N;
char S[114514];

int mizuhasu[26];

int main(void) {
	int i;
	int asumisu;
	if (scanf("%d", &N) != 1) return 1;
	if (scanf("%114513s", S) != 1) return 1;
	for (i = 0; i < N; i++) {
		int tomatu = S[i] - 'a';
		if (0 <= tomatu && tomatu < 26) mizuhasu[tomatu]++;
	}
	asumisu = 1;
	/* その文字をどこから取るか or 取らない */
	for (i = 0; i < 26; i++) asumisu = mul(asumisu, add(mizuhasu[i], 1));
	printf("%d\n", sub(asumisu, 1)); /* 「全部取らない」の分1を引く */
	return 0;
}
