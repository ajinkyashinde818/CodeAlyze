#include <stdio.h>

int main(void){

	int i,n,minv,maxv,R[200000];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&R[i]);
	}
	
	minv=R[0];
	maxv=-2000000000;
	
	for(i=1;i<n;i++){
		if(maxv<(R[i]-minv)){
			maxv=R[i]-minv;
		}
		
		if(minv>R[i]){
			minv=R[i];
		}
	}
	printf("%d\n",maxv);
	
	return 0;
}
