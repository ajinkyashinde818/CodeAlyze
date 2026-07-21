#include <stdio.h>

int main(){
	int A,B,K,j=1;
	int num[10000];
	scanf("%d %d %d",&A,&B,&K);
	for(int i=1;i<=10000;i++){
		if((A%i==0) && (B%i==0)){
			num[j] = i;
			j++;
		
	}
}

printf("%d\n",num[j-K]);
	return 0;
}
