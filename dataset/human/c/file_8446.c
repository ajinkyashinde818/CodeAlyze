#include<stdio.h>
int main(){
	int N,M,i,i2,A[200],k=0,toread;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=1;i<=M;i++){
		for(i2=0;i2<N-1;i2++){
			if(A[i2]%i>A[i2+1]%i){
				toread=A[i2];
				A[i2]=A[i2+1];
				A[i2+1]=toread;
			}
		}
	}
	for(i=0;i<N;i++){
		printf("%d\n",A[i]);
	}
	return 0;
}
