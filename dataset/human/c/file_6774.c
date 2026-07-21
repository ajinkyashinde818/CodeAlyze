#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

void binary_search(int n,int k,int a[n],int *min,int *max);

int main(void)
{

	int n,k;
	int *a;
	int maxa=INT_MIN;
	int mina=1;
	int x;
	
	scanf("%d %d",&n,&k);
	a=(int *)malloc(sizeof(int)*(n));
	
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		if(maxa<a[i])
		{
			maxa=a[i];
		}
	}
	
	binary_search(n,k,a,&mina,&maxa);
	printf("%d",mina);
	
	free(a);
	a=NULL;
	return 0;
}

void binary_search(int n,int k,int a[n],int *min,int *max)
{
	int mid=((*min)+(*max))/2;
	int b=0;
	int i;
	for(i=0;i<n;i++)
	{
		b+=((a[i]+mid-1)/mid)-1;
	}
	if(b<=k)
	{
		(*max)=mid;
	}
	else
	{
		(*min)=mid+1;
	}
	if((*min)!=(*max))
	{
		binary_search(n,k,a,min,max);
	}
	
}
