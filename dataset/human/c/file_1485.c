#include<stdio.h>
int main()
{
	char x,y,A,B,C,D,E,F;
	scanf("%c %c",&x,&y);
	A=10;
	B=11;
	C=12;
	D=13;
	E=14;
	F=15;
	if(x<y){
		printf("<\n");
	}
	else if(x>y){
		printf(">\n");
	}
	else{
		printf("=\n");
	}
	return 0;
}
