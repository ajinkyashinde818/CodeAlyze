#include<stdio.h>
int main(void){
  char *s="python3 -c\""
"n,b,*a=map(int,open(0).read().split())\n"
"a=set(a)\n"
"d=i=0\n"
"c=1\n"
"while i<n:i+=1;b=(c+d)%(10**9+7)*(not{i}&a);c,d=b,c\n"
"print(b)\n"
"\"";
  system(s);
  return 0;
}
