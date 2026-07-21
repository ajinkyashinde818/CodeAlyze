#include <stdio.h>

int main(void){
	int A,B,K;
	int count=0;
	int i;
	scanf("%d %d %d",&A,&B,&K);
if(A>B){ i = B; }
    	else{ i = A; }
	for(i; i<=A && i<=B; i--){
		if(A%i==0 && B%i==0){
			count++;
		}
		if(count==K){
			printf("%d\n",i);
			break;
		}
	}
}
