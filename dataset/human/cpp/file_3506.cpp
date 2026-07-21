#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<queue>
#include<map>
using namespace std;
int a[100005],b[100005];
int x=0,n,k=0;
long long sum=0;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0)
		{
			x++;
		}
		b[k++]=abs(a[i]);
		sum+=abs(a[i]);
	}
	if(x%2==0)
		printf("%lld\n",sum);
	else
	{
		sort(b,b+k);
		printf("%lld\n",sum-2*b[0]);
	}
	return 0;
}
