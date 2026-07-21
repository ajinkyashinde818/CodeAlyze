#include<stdio.h>
int main(void)
{
	int a,b,c,d,x,y;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	x=a*b;
	y=c*d;
	if(x>y) printf("%d\n",x);
	else if(x<y) printf("%d\n",y);
	else printf("%d\n",x);
	return 0;
}
