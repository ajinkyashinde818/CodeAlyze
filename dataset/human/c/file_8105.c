#include<stdio.h>
int main(void)
{
	int a,b,c,d,e,f;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	e=a*b;
	f=c*d;
	if(e>f){
		printf("%d\n",e);
	}
	if(f>e){
		printf("%d\n",f);
	}
	else if(e==f){
		printf("%d\n",e);
	}
	return 0;
}
