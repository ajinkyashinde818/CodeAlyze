#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define int64 long long

int main()
{
	int64 nn, mm, xx;
	scanf("%lld %lld %lld", &nn, &mm, &xx);
	int64 cc[nn], aa[nn][mm];
	for(int64 ii = 0;ii < nn;ii++)
	{
		scanf("%lld", &cc[ii]);
		for(int64 jj = 0;jj < mm;jj++)
		{
			scanf("%lld", &aa[ii][jj]);
		}
	}
	int64 ans = 10000000, tmp[mm], cnt, flag = 0, tariteru;
	for(int64 bit = 1;bit < (1 << nn);bit++)
	{
		cnt = 0;
		tariteru = 1;
		for(int64 ii = 0;ii < mm;ii++)
		{
			tmp[ii] = 0;
		}
		for(int64 ii = 0;ii < nn;ii++)
		{
			if(bit & 1 << ii)
			{
				for(int64 jj = 0;jj < mm;jj++)
				{
					tmp[jj] += aa[ii][jj];
				}
				cnt += cc[ii];
			}
		}
		for(int64 ii = 0;ii < mm;ii++)
		{
			if(tmp[ii] < xx)
			{
				tariteru = 0;
			}
		}
		if(ans > cnt && tariteru)
		{
			ans = cnt;
			flag = 1;
		}
	}
	if(flag)
	{
		printf("%lld\n", ans);
	}
	else
	{
		puts("-1");
	}
	
	return 0;
}
