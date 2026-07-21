#include<stdio.h>
int main(void)
{
	int A,B,x;
	scanf("%d %d",&A,&B);
	x=B/A;
	if(A==1){
		printf("%d\n",B);
	}
	else if(A>B||A==B){
		printf("%d\n",1);
	}
	else if(B%A!=0){
		printf("%d\n",x+1);
	}
	else{
		printf("%d\n",B/A);
	}
	return 0;
}
