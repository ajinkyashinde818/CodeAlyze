#include<stdio.h>
int main(void)
{
	int e,y,M,T,S,H;
	scanf("%d %d",&e,&y);
	if(e==0){
		if(1868<=y && 1911>=y){
			printf("M%d\n",44-(1911-y));
		}
		if(1912<=y && 1925>=y){
			printf("T%d\n",14-(1925-y));
		}
		if(1926<=y && 1988>=y){
			printf("S%d\n",63-(1988-y));
		}
		if(1989<=y && 2016>=y){
			printf("H%d\n",28-(2016-y));
		}
	}
	else if(e==1){
		printf("%d\n",1867+y);
	}
	else if(e==2){
		printf("%d\n",1911+y);
	}
	else if(e==3){
		printf("%d\n",1925+y);
	}
	else{
		printf("%d\n",1988+y);
	}
	return 0;
}
