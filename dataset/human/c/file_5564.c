#include<stdio.h>

int main(){
	int i,n,count = 0,prime[10001]={2};
	long x;
	
	for( x = 3; count < 10000; x += 2 ){
		for( i = 1;; i++ ){
			if( prime[i] == 0 ){
				prime[i] = x;
				count++;
				break;
			}
			if( x % prime[i] == 0 ) break;
		}
	}
	
	while( scanf("%d", &n), n != 0 ){
		long total = 0;
		for( i = 0; i < n; i++ ) total += prime[i];
		printf("%ld\n", total);
	}
	return 0;
}
