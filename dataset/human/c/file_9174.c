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
	int n,k;
	int h[100003];
	int cnt = 0;

	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i){
		scanf("%d",&h[i]);
		if(h[i] >= k)	++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
