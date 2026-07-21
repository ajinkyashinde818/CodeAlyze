#include <stdio.h>

int main(void){

	long N;
	long K;
	long T;
	
	long A;
	A=0;
	
	long i;
	
	int ret;
	
	ret = scanf("%ld %ld",&N,&K);
	
	for (i=1; i<=N; i++){
		
		scanf("%ld",&T);
		
		if ( T >= K ){A++;}
		
	}
	
	printf("%ld",A);
	


}
