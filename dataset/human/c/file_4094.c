#include<stdio.h>
int main(void){
	int A,B,K,i,j;
	int a[100];
	scanf("%d %d %d",&A,&B,&K);
	i=A;
	j=0;
	while(i>0){
		if(A%i==0 && B%i==0){
			a[j]=i;
			j++;
		}
		i--;
	}
	printf("%d\n",a[K-1]);
	return 0;
}
