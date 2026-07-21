#include<stdio.h>
int main(void){
  char *s="python3 -c\""
"\n"
"input();s=input()\n"
"a,*b=map(s.count,set(s));a+=1\n"
"for t in b:a=-~t*a%(10**9+7)\n"
"print(a-1)\n"
"\"";
  system(s);
  return 0;
}
