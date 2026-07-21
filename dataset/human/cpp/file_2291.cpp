#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    long long n,i=0,sum=0,s=0;
    scanf("%lld",&n);
    long long a[n];
    for(i=0;i<n;i++)
    {
    	scanf("%lld",&a[i]);
    	if(a[i]<0)
    	sum++;
	}
	for(i=0;i<n;i++)
		{
			if(a[i]<0)
		{
			a[i]=-a[i];
		}
		s=s+a[i];
	}
	sort(a,a+n);
	if(sum%2==0)
	{
		printf("%lld",s);
	}
	else
	{
		s=s-2*a[0];
		printf("%lld",s);
	}
	
    return 0;
}
