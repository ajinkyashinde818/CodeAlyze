#include<stdio.h>
int main(void){
	int E,Y;
	scanf("%d %d",&E,&Y);
	if(E==0){
		if(1989<=Y&&Y<=2016){
			printf("H%d\n",Y-1988);
		}
		else if(1926<=Y){
			printf("S%d\n",Y-1925);
		}
		else if(1912<=Y){
			printf("T%d\n",Y-1911);
		}
		else if(1868<=Y){
			printf("M%d\n",Y-1867);
		}
	}
	else if(E==1){
		printf("%d\n",1867+Y);
	}
	else if(E==2){
		printf("%d\n",1911+Y);
	}
	else if(E==3){
		printf("%d\n",1925+Y);
	}
	else if(E==4){
		printf("%d\n",1988+Y);
	}
	return 0;
}
