#include<stdio.h>

int main(){
	int a,b;
	int i,j;
	int ch;
	int check = 0;

	while(scanf("%d %d",&a,&b),b){
		ch = 0;
		for(i = 0; i < a; i++){
			for(j = 0; j < b; j++){
				if(ch % 2 == 0){
					printf("#");
				}else{
					printf(".");
				}
					if(b % 2 == 0 && j % 2 != 0 && j == b-1) ch--;
					ch++;
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
