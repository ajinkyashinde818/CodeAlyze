#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define int64 long long

int64 aa[200000];
int64 memo[200000] = {0};
int64 flag = 0;

int64 go(int64 kk, int64 here)
{
	if(memo[here] && !flag)
	{
		int64 loop = memo[here] - kk;
		flag = 1;
		int64 next = (kk % loop) - 1;
		if(next < 0)
		{
			next += loop;
		}
		return go(next, aa[here]);
	}
	else
	{
		memo[here] = kk;
		if(kk == 0)
		{
			return here;
		}
		else
		{
			return go(kk - 1, aa[here]);
		}
	}
}

int main()
{
	int64 nn, kk;
	scanf("%lld %lld", &nn, &kk);
	for(int64 ii = 0;ii < nn;ii++)
	{
		scanf("%lld", &aa[ii]);
		aa[ii]--;	//街の番号と配列の添字を合わせる
	}
	int64 ans = go(kk, 0);
	ans++;
	printf("%lld\n", ans);
	return 0;
}
