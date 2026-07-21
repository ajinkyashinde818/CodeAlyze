#include<stdio.h>
int main(void)
{
	int e,y,i;
	scanf("%d %d",&e,&y);
	if(e==0){
		if(y>=1868&&y<=1911){
			printf("M%d\n",y-1867);
		}
		if(y>=1912&&y<=1925){
			printf("T%d\n",y-1911);
		}
		if(y>=1926&&y<=1988){
			printf("S%d\n",y-1925);
		}
		if(y>=1989&&y<=2016){
			printf("H%d\n",y-1988);
		}
	}
	else{
		if(e==1){
			printf("%d\n",1868+(y-1));
		}
		if(e==2){
			printf("%d\n",1912+(y-1));
		}
		if(e==3){
			printf("%d\n",1926+(y-1));
		}
		if(e==4){
			printf("%d\n",1989+(y-1));
		}
	}
	return 0;
}
