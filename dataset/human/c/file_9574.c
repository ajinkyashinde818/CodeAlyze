#include <stdio.h>
int main(){
	int N,D,X,C;
	scanf("%d",&N);
	scanf("%d",&D);
	scanf("%d",&X);
	int A[N];
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	C=0;
	for(int i=0;i<N;i++){
		//一人目は1,A[0]+1,2A[0]+1<=D//
		C = C + 1+ (D-1)/A[i]; 
	}
	printf("%d",C + X);
	return 0;
}
