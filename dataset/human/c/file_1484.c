#include<stdio.h>
#include<string.h>
char ch1,ch2;
int main(){
	scanf("%c %c",&ch1,&ch2);
	ch1-='A';ch2-='A';
	if(ch1>ch2)
		printf(">\n");
	else if(ch1==ch2)
		printf("=\n");
	else
		printf("<\n");
	return 0;
}
