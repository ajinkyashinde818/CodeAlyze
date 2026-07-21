#include <stdio.h>
 
int main() {
	int prime[10000];
	int i,j,k,n;
	prime[0]=prime[1]=2;


	for(i=2;j<10000;i++){
		for(k=0;k<j;k++){
			if(i%prime[k]==0)break;
		}
		if(k>=j){
			prime[j]=i;
			j++;
		}
	}
	
	for(i=1;i<10000;i++){
		prime[i]+=prime[i-1];	
	}
	
	while(1){
		scanf("%d", &n);
		if(n==0) break;
		printf("%d\n", prime[n-1]);
	}
	return 0;
}
