#include<stdio.h>

int main(void){
	int K,N;
	scanf("%d %d\n",&K,&N);
	int A[N];
	for(int i=0;i<N;i++){
		scanf("%d \n",&A[i]);
	}

	int tem=0;
	for(int i=0;i<N-1;i++){

		int L = A[i+1]-A[i];
		if(L > tem)tem = L;
	}
	int M = K-A[N-1]+A[0];
	if(M>tem)tem = M;

	printf("%d",K-tem);

    return 0;
}
