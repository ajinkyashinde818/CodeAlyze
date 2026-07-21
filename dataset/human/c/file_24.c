#include<stdio.h>
int main(void){
  char *s="python3 -c\""
"r,g,b,n=map(int,input().split());print(sum((n-j)%b<1for i in range(0,n+1,r)for j in range(i,n+1,g)))\n"
"\"";
  system(s);
  return 0;
}
