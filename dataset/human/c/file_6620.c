#include<stdio.h>
#define R_MAX 200000
int main(){
	int i,N;
	int R[R_MAX];
	int maxv, minv;

	scanf("%d",&N);
	for(i=0; i<N; i++){
		scanf("%d",&R[i]);
	}

	maxv = -2000000000;
	minv = R[0];

	for(i=1; i < N; i++){
		if(maxv<R[i]-minv){
			maxv = R[i]-minv;
		}
		if(minv>R[i]){
			minv = R[i];
		}
	}

	printf("%d\n",maxv);
	return 0;
}
