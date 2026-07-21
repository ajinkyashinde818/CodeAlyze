#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,i,ara[200010],sum,sss,w,mm;
	while(scanf("%lld",&n)==1)
	{
		sum = 0;
		sss = 0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&ara[i]);
			if(i!=n-1)
				sum = sum + ara[i];
			//else
				//sss = sss + ara[i];
		}
		//printf("%d %d\n",sum,sss);
		sss = ara[n-1];
		mm = 99999999999999;
		w = abs(sss-sum);
		mm = min(mm,w);
		for(i=n-2;i>0;i--)
		{
			sum = sum - ara[i];
			sss = sss + ara[i];
			w = abs(sum-sss);
			mm = min(mm,w);
		}
//		mm = abs(sum-sss);
//		if(sum>sss)
//		{
//			for(i=n/2-1;i>0;i--)
//			{
//				sss = sss + ara[i];
//				sum = sum - ara[i];
//				w = abs(sum-sss);
//				mm = min(mm,w);
//			}
//		}
//		else if(sum<sss)
//		{
//			for(i=n/2;i<n-1;i++)
//			{
//				sss = sss - ara[i];
//				sum = sum + ara[i];
//				w = abs(sum-sss);
//				mm = min(mm,w);
//			}
//		}
//		else
//			mm = 0;
		printf("%lld\n",mm);
	}
    return 0;
}
