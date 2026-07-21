/*

	メモ：10000番目の素数は104,729
	∴サイズは105,000あれば良い。

*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 105000

void makePrime();

bool prime[SIZE];
int prime2[SIZE];

int main(){
	
	int i=0;
	int sum;
	int n;
	
	makePrime();
	
	while(1){
		
		scanf("%d", &n);
		
		if(n==0){
			
			break;
			
		}
		
		sum = 0;
		
		for(i=1; i<=n; i++){
			
			sum += prime2[i];
			
		}
		
		printf("%d\n", sum);
		
	}
	
	return 0;
	
}


void makePrime(){
	
	int i, k;
	int idx = 2;
	
	prime[0] = 0;
	prime[1] = 0;
	
	for(i=2; i<SIZE; i++){
		
		if(i%2 == 1){
			prime[i] = 1;
		}
		
	}
	
	
	prime[2] = 1;
	
	prime2[1] = 2;
	
	
	for(i=3; i<SIZE; i+=2){
		
		if(prime[i]){
			
			prime2[idx] = i;
			idx++;
			
			for(k=i+i; k<SIZE; k+=i){
				
				prime[k] = 0;
				
			}
			
		}
		
	}
	
}
