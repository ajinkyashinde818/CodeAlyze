#include<stdio.h>
int main(){
	int K,N;
	int A[3];
	int Max=0;
	scanf("%d",&K);
	scanf("%d",&N);
	scanf("%d",&A[0]);
	A[2]=A[0];
	for(int i=0;i<N-1;i++){
		scanf("%d",&A[1]);
		if(A[1]-A[2]>Max){
			Max=A[1]-A[2];
		}
		A[2]=A[1];
	}
	if((K-A[1])+A[0]>Max)Max=(K-A[1])+A[0];
	printf("%d",K-Max);
}
