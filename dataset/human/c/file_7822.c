#include<stdio.h>
int main(void)
{
    int i,a,b,c;
	scanf("%d",&a);
	for(i=0;i<a;i++){
	scanf("%d%d",&b,&c);
	if(b%c==0){
	printf("%d\n",c);
	}
	else{
	printf("%d\n",b%c);
	}
	}
	return 0;
	}
