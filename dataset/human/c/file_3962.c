#include <stdio.h>

int main(void)
{
	int A,B,K,p,i;
	int s[100];
	p = 0;
	scanf("%d %d %d",&A,&B,&K);
	for(i = 1;i <= A||i <= B;i++){
		if(A % i == 0 && B % i == 0){
			s[p] = i;
			p++;
		}
	}
	printf("%d\n",s[p - K]);
	return 0;
}
