#include <stdio.h>
int main(void){
char s[100],ss[10];
  scanf("%s %s",s,ss);
  if(s[0]==ss[0]){printf("=");}
  else if(s[0]<ss[0]){printf("<");}
                    else if(s[0]>ss[0]){printf(">");}
}
