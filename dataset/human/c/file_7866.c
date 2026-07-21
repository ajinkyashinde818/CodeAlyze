#include <stdio.h>
int occu[200001],cnt[200001],a[200001];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int empty=n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		++cnt[a[i]];
		if (a[i]-cnt[a[i]]>=0)
		{
			if (!occu[a[i]-cnt[a[i]]])
				--empty;
			++occu[a[i]-cnt[a[i]]];
		}
	}
	for (int i=1;i<=m;++i)
	{
		int idx,after;
		scanf("%d%d",&idx,&after);
		int before=a[idx];
		if (before-cnt[before]>=0)
		{
			--occu[before-cnt[before]];
			if (!occu[before-cnt[before]])
				++empty;
		}
		--cnt[before];
		a[idx]=after;
		++cnt[after];
		if (after-cnt[after]>=0)
		{
			if (!occu[after-cnt[after]])
				--empty;
			++occu[after-cnt[after]];
		}
		printf("%d\n",empty);
	}
	return 0;
}
