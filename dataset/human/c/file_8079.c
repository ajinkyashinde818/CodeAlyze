#include<stdio.h>
int main(void)
{
	int A,B,C,D,N,M;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	if(A*B>=C*D){
			M=A*B;
			printf("%d\n",M);
	}
	if(A*B<C*D){
			N=C*D;
			printf("%d\n",N);
	}
	return 0;
}
