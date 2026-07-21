#include<stdio.h>
int main(void){
  char *s="python3 -c\""
"n,*a=map(int,open(0).readlines());c,s=1,a[0]\n"
"while s!=2and c<n:c+=1;s=a[s-1]\n"
"print(c*(c<n)or-1)\n"
"\"";
  system(s);
  return 0;
}
