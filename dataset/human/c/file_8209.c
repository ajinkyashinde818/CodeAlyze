#include<stdio.h>
int main(void)
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	e=a*b;
	f=c*d;
	if(e>f){
		printf("%d",e);
	}
	else if(f>e){
		printf("%d",f);
	}
	else{
		printf("%d",e);
	}
	return 0;
}
