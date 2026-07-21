#include <stdio.h>
#include <string.h>

long  N,M,X;
long X,C[20],A[20][20];
long min=10010000;

int main(){
	scanf("%ld%ld%ld",&N,&M,&X);
	int i,j;
	long dd=0;
	for(i=0;i<N;i++){
		scanf("%ld",C+i);
		for(j=0;j<M;j++){
			scanf("%ld",&A[i][j]);
		}
	}
		
	for (int bit = 0; bit < (1<<N); ++bit) {
		long sum=0;
		long tmp[20];
		for(i=0;i<N;i++){
			tmp[i]=0;
		}
		for ( i = 0; i < N; ++i) {
			if (bit & (1 << i)) {
				sum += C[i];
				for(j=0;j<M;j++)tmp[j]+=A[i][j];
			}
        }
		int flag=1;
		for(i=0;i<M;i++){
			if(tmp[i]<X)flag=0;
		}
		if(flag){
			if(min>sum)min=sum;
		}
    }
	if(min==10010000)printf("-1\n");
	else	printf("%ld",min);
	return 0;
}
