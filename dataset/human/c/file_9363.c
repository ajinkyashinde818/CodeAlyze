#include<stdio.h>
int main(void){
	int N, D,X,i;
	int A[100];
	scanf("%d %d %d", &N, &D, &X);
	for(i = 0; i < N;i++){
		scanf("%d",&A[i]);
	}
	for(i = 0; i < N; i++){
		if (D%A[i] == 0){
			X += D / A[i];
		}
		else{
			X += D / A[i]+1;
		}
	}
	printf("%d", X);
	return 0;
}
