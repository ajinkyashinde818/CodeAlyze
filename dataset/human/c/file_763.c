/*
	submission # - User: herp_sy
	https://atcoder.jp/contests/

	coding: utf-8
	lang: C (GCC 5.4.1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

int main(int argc, char const *argv[])
{
	int n;
	char s[100003];
	TLong ans = 1, charcnt[26] = { 0 };

	scanf("%d", &n);
	scanf("%s", s);

 	for(int i = 0; i < n; ++i)	++charcnt[s[i] - 'a'];
 	for(int i = 0; i < 26; ++i) ans = (TLong)ans * (charcnt[i] + 1) % TBMod;
 	printf("%lld\n", (ans + TBMod - 1) % TBMod);
}
