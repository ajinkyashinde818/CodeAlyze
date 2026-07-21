#include<stdio.h>

int main(void){
	int x=1,y[100000],z=1,a=0,b=1;
	while(x!=0){
		scanf("%d",&x);
		if(x!=0){
			y[z]=x;
			z++;
		}
	}
	while(y[b]!=0){
		printf("Case %d: %d\n",a+1,y[b]);
		b++;
		a++;
	}
	return 0;
}
