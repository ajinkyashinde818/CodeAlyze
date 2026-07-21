#include <stdio.h>

int main(void){
	int N;
	int A[20],B[50],C[50];
	int i;
	int sum;

	scanf("%d",&N);
	for(i=0; i<N; i++) scanf("%d",&A[i]);  //input A[i]
	for(i=0; i<N; i++) scanf("%d",&B[i]);  //input B[i]
	for(i=0; i<N-1; i++) scanf("%d",&C[i]);//input C[i]

	sum=0;
	for(i=0; i<N; i++){
		int d;
		d = A[i]-1;
		sum+=B[d]; 
		if(d+1==A[i+1]-1) sum+=C[d];
	}

	printf("%d\n",sum );
}
