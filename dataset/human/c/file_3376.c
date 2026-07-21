#include<stdio.h>
#include<stdlib.h>

int g(char*s,char*t){
	int i=0;
	while(s[i]!='\0'&&t[i]!='\0')
		if(s[i]!=t[i++])return 0;
	if(s[i]=='\0'&&t[i]!='\0')return 0;
	return 1;
}

int f(char*s){
	if(s[0]=='\0'){printf("YES\n");exit(0);}
	if(g(s,"dream"))f(&s[5]);
	if(g(s,"dreamer"))f(&s[7]);
	if(g(s,"erase"))f(&s[5]);
	if(g(s,"eraser"))f(&s[6]);
}


int main(void){
	char s[100000];
	scanf("%s",s);
	int i=0;
	f(s);
	printf("NO\n");
}
