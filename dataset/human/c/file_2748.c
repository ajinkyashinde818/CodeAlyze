#include <stdio.h>
int main(void){
	int K, S;
	int x, y, z;
	int n, N=0;

	scanf("%d %d",&K,&S);

	
	for(x=0; x<=K; x++){
		
		for(y=0; y<=K; y++){
			
			n=S-x-y;
			if(0<=n&&n<=K) N=N+1;
		}
	}
	printf("%d",N);



	return 0;
}
