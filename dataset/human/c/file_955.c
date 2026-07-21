#include <stdio.h>

int main(void){
	int e,y;
	scanf("%d%d",&e,&y);
	if(e == 1){printf("%d\n",1867+y);}
	if(e == 2){printf("%d\n",1911+y);}
	if(e == 3){printf("%d\n",1925+y);}
	if(e == 4){printf("%d\n",1988+y);}
	if(e == 0){
		if(1868 <= y && y <= 1911){printf("M%d\n",y-1867);}
		if(1912 <= y && y <= 1925){printf("T%d\n",y-1911);}
		if(1926 <= y && y <= 1988){printf("S%d\n",y-1925);}
		if(1989 <= y && y <= 2016){printf("H%d\n",y-1988);}
	}
	return 0;
}
