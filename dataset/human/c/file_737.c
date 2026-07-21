#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define DIV 1000000007

int main(void) {
	long long n;
	char s[100000] = { 0 };
	long long cnt[26] = { 0 };
	long long ans = 1;

	scanf("%lld", &n);
	scanf("%s", s);

	for (int i = 0; i < n; i++) cnt[s[i] - 97]++;
	for (int i = 0; i < 26; i++) ans = ans * (cnt[i] + 1) % DIV;
	printf("%lld", ans - 1);

	return 0;
}
