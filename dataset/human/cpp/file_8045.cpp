#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
long long int a[200005];
int main()
{
	long long int n,sum1=0,sum2=0,i,min=0,j,sum=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		min+=fabs(a[i]);
		sum+=a[i];			
	}	
	for(i=n-1;i>0;i--)
	{
		sum1+=a[i];
		if(fabs(2*sum1-sum)<min)
		{min=fabs(2*sum1-sum);}	
	}
	printf("%lld\n",min);
}
