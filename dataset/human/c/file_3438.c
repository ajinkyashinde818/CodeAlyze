#include<stdio.h>

struct zhen
{
	long long teleporter;
	int flag = 0;/*判断是否来过*/
}d[200005];


struct cc
{
	long long des;
}c[200005];

int main()
{
	long long n, k, i,j,bj,flag0=0;
	scanf("%lld%lld", &n, &k);
	for (i = 1; i <= n; i++)/*输入每个镇的传送门*/
		scanf("%lld", &d[i].teleporter);
	c[0].des = 1;/*第几次在哪个镇*/
	d[1].flag = 1;
	for (i = 1; i <= k; i++)
	{
		c[i].des = d[c[i-1].des].teleporter;
		if (d[c[i].des].flag == 1)
		{
			bj = i;
			flag0 = 1;/*表示存在循环*/
			break;
		}
		d[c[i].des].flag = 1;
	}
	if (flag0)
	{
		for (j = 0; j < bj; j++)
			if (c[j].des == c[bj].des)
				break;
		long long cha = bj - j,ys;
		ys = (k - j) % cha;
		printf("%lld\n", c[j  + ys].des);
	}
	else
	{
		printf("%lld\n", c[k].des);
	}
	return 0;
}
