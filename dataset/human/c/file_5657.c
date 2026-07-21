#include <stdio.h>
int main(void)
{int A,B,C,D,N,K,S,Y,Z,k,l,tmp;
	long long int x,m,i;
	scanf("%lld",&x);
	m=x/11;
	i=x%11;
	if(i==0)
	printf("%lld",m*2);
	else if(i>=7)
	printf("%lld",m*2+2);
	else
	printf("%lld",m*2+1);
		
	


	return 0;
}
