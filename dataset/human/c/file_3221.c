#include<stdio.h>

int main()
{
	int k,n,i,min,a[1000000];
	
	scanf("%d%d",&k,&n);
	for(i=0;i<n;i++){
	  scanf("%d",&a[i]);
	}
	
	min=a[0]+k-a[n-1];
	for (i=1;i<n;i++){
	  if (a[i]-a[i-1]>min)
	    min=a[i]-a[i-1];
	}
	
	printf("%d",k-min);
}
