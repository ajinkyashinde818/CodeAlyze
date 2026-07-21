#include<stdio.h>

int main(void)
{
	int j,minv,maxv,n;
	int R[200000];
	     
	scanf("%d",&n);
	for(j = 0;j < n;j++){
		scanf("%d",&R[j]);
	}
	minv = R[0];
	maxv = R[1] -R[0];
	for(j = 1;j < n;j++){
		if(maxv > R[j] - minv)maxv = maxv;
		else maxv = R[j] - minv;
		if(minv > R[j])minv = R[j];
		else minv = minv;
	}
        printf("%d\n",maxv);
	return 0;
}
