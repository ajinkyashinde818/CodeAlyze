#include<stdio.h>
#include<stdlib.h>

int main(){
	int N;
	int *A;
	int i,c;
	long int a;
	int min=100000000,max=-100000000;
	scanf("%d",&N);
	A=(int*)malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
		scanf("%d ",&A[i]);
	}
	for(i=0;i<N;i++){
		if(A[i]<0){
			c++;
			if(max<A[i])max=A[i];
			a-=A[i];
		}
		else{
			if(min>A[i])min=A[i];
			a+=A[i];
		}
	}
	if(c%2==0)printf("%ld\n",a);
	else{
		if(min+max<0)printf("%ld\n",a-2*min);
		else printf("%ld\n",a+2*max);
	}
	return 0;
}
