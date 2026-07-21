#include<stdio.h>
int main(void)
{
	int e,y;
	scanf("%d %d",&e,&y);
	if(e==1){
		e=1867+y;
		printf("%d\n",e);
	}
	else if(e==2){
		e=1911+y;
		printf("%d\n",e);
	}
	else if(e==3){
		e=1925+y;
		printf("%d\n",e);
	}
	else if(e==4){
		e=1988+y;
		printf("%d\n",e);
	}
	if(y>=1868&&y<=1911){
		y=y-1867;
		printf("M%d\n",y);
	}
	else if(y>=1912&&y<=1925){
		y=y-1911;
		printf("T%d\n",y);
	}
	else if(y>=1926&&y<=1988){
		y=y-1925;
		printf("S%d\n",y);
	}
	else if(y>=1989){
		y=y-1988;
		printf("H%d\n",y);
	}
	return 0;
}
