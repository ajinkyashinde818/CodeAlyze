#include<stdio.h>
int main(void)
{
	int a,b,c,d,x,y;
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	
	x=a*b;
	y=c*d;
	if(x>y) {
		printf("%d\n",x);
	}
	else if(x==y) {
		printf("%d\n",x);
	}
	else if(x<y) {
		printf("%d\n",y);
	}
	return 0;
}
