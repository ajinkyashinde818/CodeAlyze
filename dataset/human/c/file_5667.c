#include<stdio.h>
#define M -1000000000
int main()
{
	int a;
	int n,min,max=M;
	scanf("%d",&n);
	scanf("%d",&a); 
	min = a;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a);
		if(max<a-min)
		{
			max = a-min;
		}
		if(min>a)
		{
			min=a;
		}
		
	}
	printf("%d\n",max);
	return 0;
 }
