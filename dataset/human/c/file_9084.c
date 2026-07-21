#include <stdio.h>
int main()
{
	int i,n,k,a[100000],c=0;
	scanf("%d",&n);
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	
		if(a[i]>=k)
		{
			c = c+1;
		}
    }
	printf("%d",c);
	return 0;
}
