#include<stdio.h>
#define gc() getchar()
int in() {   // 非負整数の入力
	int n = 0; int c;
	c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}
int a[200000];
int main()
{
	int d, i,k,n,max;
	k = in(), n = in();
	a[0] = in(),a[1]=in();
	max = a[1] - a[0];
	for (i = 2; i < n; i++)
	{
		a[i] = in(); d = a[i] - a[i - 1];
		if (d > max) max = d;
	}
	if (k - a[n - 1] + a[0] > max) max = k - a[n - 1] + a[0];
	printf("%d", k - max);
}
