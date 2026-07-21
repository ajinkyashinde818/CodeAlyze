#include<stdio.h>
int main()
{
	int a,i=0,n[10020];
	scanf("%d",&a);
	while(a!=0)
	{
		i++;
		n[i]=a;
		scanf("%d",&a);
	}
	for(a=1;a<=i;a++)
	{
		printf("Case %d: %d",a,n[a]);
		
		printf("\n");
	}
	
	return 0;
}
