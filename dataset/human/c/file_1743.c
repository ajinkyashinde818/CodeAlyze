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
	int a[23],b[23],c[23];
	int sum = 0;

	scanf("%d",&n);
	for (int i = 0; i < n; ++i)	scanf("%d",&a[i]);
	for (int i = 0; i < n; ++i)	scanf("%d",&b[i]);
	for (int i = 0; i < n - 1; ++i)	scanf("%d",&c[i]);
	for (int i = 0; i < n; ++i)
	{
		sum += b[a[i] - 1];
		if(i > 0){
			if(a[i - 1] + 1 == a[i])	sum += c[a[i - 1] - 1];
		}
	}
	printf("%d\n", sum);
	return 0;
}
