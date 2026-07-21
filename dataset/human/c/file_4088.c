#include<stdio.h>

int main()
{
	int A,B,K,i,counter;
	counter = 0;
	scanf("%d %d %d",&A,&B,&K);
	for(i=100;i>=1;i--){
		if(A % i == 0 && B % i == 0)
		counter++;
		if(counter == K){
			printf("%d",i);
			break;
		};
	};
}
