#include <stdio.h>
int main(void)
{
	int e,y,i;
	scanf("%d %d",&e,&y);
	if(e==0){
		if(y>=1868 && y<=1911){
			i=y-1867;
			printf("M%d\n",i);
		}
		if(y>=1912 && y<=1925){
			i=y-1911;
			printf("T%d\n",i);
		}
		if(y>=1926 && y<=1988){
			i=y-1925;
			printf("S%d\n",i);
		}
		if(y>=1989 && y<=2016){
			i=y-1988;
			printf("H%d\n",i);
		}
	}
	if(e==1){
		i=y+1867;
		printf("%d\n",i);
	}
	if(e==2){
		i=y+1911;
		printf("%d\n",i);
	}
	if(e==3){
		i=y+1925;
		printf("%d\n",i);
	}
	if(e==4){
		i=y+1988;
		printf("%d\n",i);
	}
	return 0;
}
