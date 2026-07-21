#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define int64 long long

int main()
{
	int64 dd, gg, min = LLONG_MAX, xx;
	scanf("%lld %lld", &dd, &gg);
	int64 pp[dd], cc[dd], score[dd];
	for(int64 ii = 0;ii < dd;ii++)
	{
		scanf("%lld %lld", &pp[ii], &cc[ii]);
		score[ii] = pp[ii] * (ii + 1) * 100 + cc[ii];
	}
	int64 tmp, kosu;
	for(int64 bit = 0;bit < (1 << dd);bit++)
	{
		tmp = 0;
		kosu = 0;
		for(int64 ii = 0;ii < dd;ii++)
		{
			if(bit & (1 << ii))
			{
				tmp += score[ii];
				kosu += pp[ii];
			}
		}
		if(tmp < gg)
		{
			for(int64 ii = dd - 1;ii >= 0;ii--)
			{
				if(!(bit & (1 << ii)))
				{
					xx = (gg - tmp) / ((ii + 1) * 100);
					if((gg - tmp) % ((ii + 1) * 100))
					{
						xx++;
					}
					if(xx > pp[ii])
					{
						break;
					}
					tmp += xx * (ii + 1) * 100;
					kosu += xx;
					break;
				}
			}
		}
		
		if(min > kosu && tmp >= gg)
		{
			min = kosu;
		}
	}
	printf("%lld\n", min);
	return 0;
}
