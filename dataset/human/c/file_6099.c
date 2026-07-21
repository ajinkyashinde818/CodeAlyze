#include<stdio.h>
int main(void)
{
	int a,b,max, min;
	scanf("%d", &a);
	int d[a];
	scanf("%d", &d[0]);
	min=d[0];
	max=-d[0];
	for(b=1; b<a; b++)
	{
		scanf("%d", &d[b]);
		if(max<d[b]-min){max=d[b]-min;}
		if(min>d[b]){min=d[b];}
		
	}
	printf("%d\n", max);
	return 0;
}
