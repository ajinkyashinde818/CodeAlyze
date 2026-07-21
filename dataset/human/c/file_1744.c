#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int *a,*b,*c;
	a = (int*)malloc(sizeof(int)*(n));
	b = (int*)malloc(sizeof(int)*(n));
	c = (int*)malloc(sizeof(int)*(n));
	int i = 0;
	int j = 0;

	while (i < n)
	{
		scanf("%d",&a[i]);
		i++;
	}

	i = 0;
	while (i < n)
	{
		scanf("%d",&b[i]);
		i++;
	}
	
	i = 0;
	while (i < n-1)
	{
		scanf("%d",&c[i]);
		i++;
	}
	i = 1;
	int st = b[a[0]-1];
	while (i < n)
	{
		st+=b[a[i]-1];
		if(a[i] == a[i-1]+1)
			st+=c[a[i-1]-1];
		//printf("st:%d, i:%d, a[i]:%d\n",st,i,a[i]);
		i++;
	}
	printf("%d\n",st);
	return(0);
}
