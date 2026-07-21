/*
	submission # - User: herp_sy
	https://atcoder.jp/contests/
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
	int n,d,x;	
	int a[103];
	scanf("%d",&n);
	scanf("%d%d",&d,&x);
	for (int i = 0; i < n; ++i)
	{
	  scanf("%d",&a[i]);
	  if(d % a[i])  x += d / a[i] + 1;
	  else x += d / a[i];
	}
	printf("%d\n", x);
	return 0;
}
