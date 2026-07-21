#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(int argc,char** argv)
{
	int X,Y;
	scanf("%x%x",&X,&Y);
	if(X > Y){
		printf(">\n");
	}
	else if(X < Y){
		printf("<\n");
	}
	else{
		printf("=\n");
	}
	return(0);
}
