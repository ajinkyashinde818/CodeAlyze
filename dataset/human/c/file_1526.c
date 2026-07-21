#include <stdio.h>
int main(int argc, char const *argv[]){
	char a,b;
	int c;
	a=getchar();
	getchar();
	b=getchar();
	c=b-a;
	if(c>0)
		printf("<");
	else if(c==0)
		printf("=");
	else if(c<0)
		printf(">");
	return 0;
}
