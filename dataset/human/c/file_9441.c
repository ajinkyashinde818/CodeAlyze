#include <stdio.h>
int main() {
	int i,n,d,count,N,D,X;
	count=0;
	scanf("%d", &N);
	scanf("%d %d",&D,&X);
	int int_arr[N];
	
	for (int i = 0; i < N; i++){
		scanf("%d", &int_arr[i]);

		for (int j = 1; j <= D; j += int_arr[i]){
		  count++;
		}
	}
	printf("%d \n",count+X );
}
