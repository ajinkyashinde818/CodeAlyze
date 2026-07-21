#include <stdio.h>

int main(void)
{
	int A,B,C;
	C=0;
	scanf(" %d %d",&A,&B);
	if(A<B){
		C=(B+A-1)/A;
		printf("%d\n",C);
	}
	else if(A>B){
		C=1;
		printf("%d\n",C);
	}
	else{
		printf("%d\n",1);
	}
	return 0;
}
