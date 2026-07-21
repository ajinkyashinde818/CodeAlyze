#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int n,step;

int main(){
	while(scanf("%d",&n)*n>0){
		step=0;
		while(n>1){
			step++;
			if(n%2)n=3*n+1; else n=n/2;
		}
		printf("%d\n",step);
	}
	return 0;
}
