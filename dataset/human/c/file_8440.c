#include<stdio.h>
int main()
{
	int N,k,i,j,A[100],M,o=0;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(k=2;k<=M;k++){
		for(i=0;i<N-1;i++){
			if(A[i]%k>A[i+1]%k){
			o=A[i];
			A[i]=A[i+1];
			A[i+1]=o;
			}
		}
	}
	for(i=0;i<N;i++){
		printf("%d\n",A[i]);
	}





}
