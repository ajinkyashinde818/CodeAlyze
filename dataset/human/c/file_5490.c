#include <stdio.h>
#include <cmath>
#include <algorithm>

#define NUM 120000

int main(){
	int table[NUM],limit;

	for(int i=0; i < NUM;i++)table[i] = 1;
	table[0] = 0;
	table[1] = 0;

	limit = sqrt(NUM);

	for(int i=2;i<=limit;i++){
		if(table[i] == 1){
			for(int k=2*i;k < NUM; k += i){
				table[k] = 0;
			}
		}
	}

	int n,count,sum;

	while(true){
		scanf("%d",&n);
		if(n == 0)break;

		sum = count = 0;
		for(int i=2; i< NUM; i++){
			if(table[i] == 1){
				sum += i;
				count++;
				if(count == n)break;
			}

		}
		printf("%d\n",sum);
	}
	return 0;
}
