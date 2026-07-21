#include<stdio.h>

#define MAX 200000

int main()
{
	int n,i,maxP=-2000000000;
	int a[MAX];
	int x,minv;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    	scanf("%d", &a[i]);
    minv = a[0];
    for(i=1;i<n;i++)
    {
    	x = a[i] - minv;
    	if(x>maxP)
    	    maxP = x;
    	if(a[i]<minv)
    	    minv = a[i];
	}
	printf("%d\n", maxP);
	return 0;
}
