#include<stdio.h>
int main(void){
  char *s="python3 -c\""
"_,a=open(0);b,c=zip(*[(abs(i),i<0)for i in map(int,a.split())]);print(sum(b)-sum(c)%2*min(b)*2)\n"
"\"";
  system(s);
  return 0;
}
