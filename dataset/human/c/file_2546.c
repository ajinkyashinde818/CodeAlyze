#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
char s[10];
scanf("%s",s);
if(s[0]==s[1]||s[0]==s[2]||s[1]==s[2]){printf("No");}
else{printf("Yes");}
return 0;
}
