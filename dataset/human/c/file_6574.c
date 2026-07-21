#include <stdio.h>
int main()
{
	int n,i,t;
	scanf("%d",&n);
	int num[n];
	for(i=0;i<n;i++)
	scanf("%d",&num[i]);
	int min=num[0],di=-2000000000;
	for(i=1;i<n;i++)
	{
		if((num[i]-min)>di)
		{
			di=num[i]-min;
		}
		if(num[i]<min)
		{
			min=num[i];
		}
		
	}
	printf("%d\n",di);
	return 0;
}
