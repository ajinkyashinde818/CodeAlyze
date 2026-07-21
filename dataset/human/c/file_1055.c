#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char s[60],t[60];
    scanf("%s",s);
    strncpy(t,s,strlen(s)-8);
    t[strlen(s)-8]='\0';
    printf("%s\n",t);
	return 0 ;
}
