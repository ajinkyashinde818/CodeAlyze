#include<stdio.h>
int main(void){
	int n,t,j,maxv,minv;
	int R[200000];
	scanf("%d\n",&n);
	for(t=0;t<=n-1;t++){
		scanf("%d\n",&R[t]);
	}
	minv=R[0];
	maxv=R[1]-R[0];
	for(j=1;j<=n-1;j++){
		if(maxv<R[j]-minv){
			maxv=R[j]-minv;
			
		}
		if(minv>R[j]){
			minv=R[j];
		}
		
	}
	printf("%d\n",maxv);
	return 0;
}
