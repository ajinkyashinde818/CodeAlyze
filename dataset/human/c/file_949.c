#include<stdio.h>
int main(void)
{	
	int e,y,x;	
	scanf("%d %d",&e,&y);
	if(e==1){
	x=1867+y;
	printf("%d\n",x);
	}
	else if(e==2){
	x=1911+y;
	printf("%d\n",x);
	}
	else if(e==3){
	x=1925+y;
	printf("%d\n",x);
	}
	else if(e==4){
	x=1988+y;
	printf("%d\n",x);
	}
	else if(e==0){
		if(y>=1868&&y<=1911){
		x=y-1868+1;
		printf("M%d\n",x);
		}
		else if(y>=1912&&y<=1925){
		x=y-1912+1;
		printf("T%d\n",x);
		}
		else if(y>=1926&&y<=1988){
		x=y-1926+1;
		printf("S%d\n",x);
		}
		else if(y>=1989&&y<=2016){
		x=y-1989+1;
		printf("H%d\n",x);
		}
		}
	return 0;
}
