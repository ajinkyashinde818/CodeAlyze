#include <stdio.h>
int main(void){
char s[100];
       int kokomade,count;
  scanf("%s",s);
  for(count=0;;){
    if(s[count]=='\0'){kokomade=count;break;}
  count++;
  }
  s[kokomade-8]='\0';
  printf("%s",s);
return 0;
}
