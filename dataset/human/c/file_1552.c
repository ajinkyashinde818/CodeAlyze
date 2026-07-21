#include <stdio.h>
#include <stdlib.h>
int main(){
	char x[100];
	char y[100];
	long a,b;
	scanf("%s %s",&x,&y);
	a=strtol(x,NULL,16);
	b=strtol(y,NULL,16);
	if (a>b)
	{
		printf(">\n");
	}else if (a<b){
		printf("<\n");
	}else{
		printf("=\n");
	}
	}
