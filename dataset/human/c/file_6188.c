#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,a[200005],max,min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[1]-a[0];
	min=a[0];
	for(i=1;i<n;i++)
	{
		max=max>a[i]-min?max:a[i]-min;
		min=min<a[i]?min:a[i];
	}
	printf("%d\n",max);
	return 0;
}
