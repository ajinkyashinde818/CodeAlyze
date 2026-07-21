#include<stdio.h>
int main(void)
{
	int E,Y,a,b;
	scanf("%d %d",&E,&Y);
	if(E==0){
		if(Y>=1868&&Y<=1911){
			a=(Y-1868)+1;
			printf("M%d\n",a);
		}
		if(Y>=1912&&Y<=1925){
			a=(Y-1912)+1;
			printf("T%d\n",a);
		}
		if(Y>=1926&&Y<=1988){
			a=(Y-1926)+1;
			printf("S%d\n",a);
		}
		if(Y>=1989&&Y<=2016){
			a=(Y-1989)+1;
			printf("H%d\n",a);
		}
	}
	if(E>0){
		if(E==1){
			b=1869+Y-2;
		}
		if(E==2){
			b=1912+Y-1;
		}
		if(E==3){
			b=1926+Y-1;
		}
		if(E==4){
			b=1989+Y-1;
		}
		printf("%d\n",b);
	}
	return 0;
}
