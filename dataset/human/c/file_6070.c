#include<stdio.h>


int main(void){
	
	int n,i,maxv,minv;
	
	int j;
	
	scanf("%d",&n);
	
	int a[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	minv=a[0];
	maxv=a[1]-a[0];
	
	for(j=1;j<=n-1;j++)
	{
		if(maxv<a[j]-minv){maxv=a[j]-minv;}
		if(minv>a[j]){minv=a[j];}
	}
	
	printf("%d\n",maxv);
    return 0;	
}
