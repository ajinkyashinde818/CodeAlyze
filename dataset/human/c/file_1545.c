#include <stdio.h>

int main(void){
	char x,y;
	int a,b;
	scanf("%c %c",&x,&y);
	switch(x){
		case 'A':
		 a=1;
		break;
		case 'B':
		 a=2;
		 break;
		case 'C':
		 a=3;
		 break;
		case 'D':
		 a=4;
		 break;
		case 'E':
		 a=5;
		 break;
		case 'F':
		 a=6;
		 break;
	}
	switch(y){
		case 'A':
		 b=1;
		break;
		case 'B':
		 b=2;
		 break;
		case 'C':
		 b=3;
		 break;
		case 'D':
		 b=4;
		 break;
		case 'E':
		 b=5;
		 break;
		case 'F':
		 b=6;
		 break;
	}
	if(a==b){
		printf("=\n");
	}else if(a<b){
		printf("<\n");
	}else{
		printf(">\n");
	}
	return 0;
}
