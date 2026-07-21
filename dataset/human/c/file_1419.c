#include<stdio.h>
int main(void){
	int a,b;
	
	scanf("%d %d",&a,&b);
	if(a<=100000&&b<=100000){
	if(a>=b)
	printf("1\n");
	else if(a==1)
	printf("%d\n",b);
	else if(b%a==0)
	printf("%d\n",b/a);
	else
	printf("%d\n",b/a+1);
	}return 0;
	}
