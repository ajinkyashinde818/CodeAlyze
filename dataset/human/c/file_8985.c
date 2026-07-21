#include <stdio.h>
int koko(int n,int k){
	if(n==1){
		return k;
	}
	else if(n%2==0){
		n=n/2;
		k++;
		return koko(n,k);
	}
	else{
		n=3*n+1;
		k++;
		return koko(n,k);
	}
}
int main(void) {
	while(1){
		int n,k=0;
		scanf("%d",&n);
		if(n==0) break;
		printf("%d\n",koko(n,k));
	}
	return 0;
}
