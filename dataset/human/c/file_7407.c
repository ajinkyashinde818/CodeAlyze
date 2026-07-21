#include<stdio.h>
int main()
{
	int a[10000];
	int j=0;
	scanf("%d",&a[j]);
	while(a[j]!=0)
	{
		j++;
		scanf("%d",&a[j]);
	}
	for(int i=0;i<j;i++)
	{
		printf("Case %d: %d",i+1,a[i]);
		printf("\n");
	}
	return 0;
}
