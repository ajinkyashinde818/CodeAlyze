#include<stdio.h>
int main(void)
{
	int E,Y,S=0;
	scanf("%d %d",&E,&Y);
	if (E==0) {
		if(Y>=1868&&Y<=1911) { 
		S=Y-1868+1;
		printf("M%d\n",S);
		}
		else if(Y>=1912&&Y<=1925) {
		S=Y-1912+1;
		printf("T%d\n",S);
		}
		else if(Y>=1926&&Y<=1988) {
		S=Y-1926+1;
		printf("S%d\n",S);
		}
		else if(Y>=1989&&Y<=2016) {
		S=Y-1989+1;
		printf("H%d\n",S);
		}
	}
	else if(E==1) {
		S=1868+Y-1;
		printf("%d\n",S);
	}
	else if(E==2) {
		S=1912+Y-1;
		printf("%d\n",S);
	}
	else if(E==3) {
		S=1926+Y-1;
		printf("%d\n",S);
	}
	else if(E==4){
		S=1989+Y-1;
		printf("%d\n",S);
	}
	return 0;
}
