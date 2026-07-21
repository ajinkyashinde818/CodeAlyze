#include<stdio.h>
int a[1000000];
int main(){
	int k,n,i,max;
	scanf("%d %d",&k,&n);
	for (i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	max=a[1]+k-a[n];
	for (i=2;i<=n;i++)
	  if (a[i]-a[i-1]>max)
	    max=a[i]-a[i-1];
	printf("%d",k-max);
}
