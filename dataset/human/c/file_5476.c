#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000

int main(){
	bool p[MAX+1];
	int n, sum;

	p[0] = false;
	p[1] = false;
	for(int i=2 ; i<=MAX ; i++){
		p[i] = true;
	}
	for(int i=2 ; i<=sqrt(MAX)+1 ; i++){
		if(p[i]==1){
			for(int j=i*2; j<=MAX; j=j+i){
				p[j] = false;
			}
		}
	}
	
	while( scanf("%d" , &n) != EOF , n){			
		sum = 0;
		for(int i=0; n>0; i++){
			if(p[i]){
				sum += i;
				n--;
			}
		}
		printf("%d\n", sum);
	}
}
