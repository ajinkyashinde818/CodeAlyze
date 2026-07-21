#include<stdio.h>
int main(void)
{
	int  A,B,C,D,x,y;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	x=A*B;
	y=C*D;
	if(x>=y){
		printf("%d\n",x);
	}
	if(y>x){
		printf("%d\n",y);
	}
	return 0;
}
