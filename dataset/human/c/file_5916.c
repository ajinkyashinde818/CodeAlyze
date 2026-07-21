#include <stdio.h>
#define N 300000

int main(void){
	int j,n,minv=0;
	int maxv=-2000000000;
	int R[N]={0};
	
	scanf("%d",&n);
	for(j=0;j<n;j++)scanf("%d",&R[j]);
	
	minv=R[0];
	for(j=1;j<=n-1;j++) {
		if(maxv<R[j]-minv)maxv=R[j]-minv;
		if(minv>R[j])minv=R[j];
	}
	
	printf("%d\n",maxv);
	
	return 0;
}
