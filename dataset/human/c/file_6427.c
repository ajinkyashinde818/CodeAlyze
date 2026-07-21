#include <stdio.h>
int main(void)
{
	int n,R[200000],i,j,maxv,minv;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%d",&R[i]);
	}
	minv=R[0];
	maxv=-2000000000;
	for(j=1;j<=n-1;j++){
		if(maxv<(R[j]-minv)){
			maxv=R[j]-minv;
		}
		if(minv>R[j]){
			minv=R[j];
		}
	}	
	printf("%d\n",maxv);
	
	return 0;
}
