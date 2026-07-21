#include<stdio.h>
int main(void)
{
	int a,b,x;
	scanf("%d %d ",&a,&b);
	x=b/a;
	if(a==1){
		printf("%d\n",b);
	}
	else if(a>b||a==b){
		printf("%d\n",1);
	}
	else if(b%a!=0){
		printf("%d\n",x+1);
	}
	else {
		printf("%d\n",b/a);
	}
	return 0;
}
