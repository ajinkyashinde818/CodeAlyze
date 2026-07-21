#include<stdio.h>

int main(void)
{
	int i,a,b,c,d=0,e;

	scanf("%d %d %d",&a,&b,&c);

	if(a>=b){
		e=b;
	}else{
		e=a;
	}

	for(i=e;;i--){
		if((a%i==0)&&(b%i==0)){
			d=d+1;
		}
		if (d>=c) break;
	}
	printf("%d\n",i);

	return 0;
}
