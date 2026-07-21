#include <stdio.h>

int judge(char n){
  int j;
  if(n=='A') j=10;
  if(n=='B') j=11;
  if(n=='C') j=12;
  if(n=='D') j=13;
  if(n=='E') j=14;
  if(n=='F') j=15;
  return(j);
}

int main(void){
  char x[2],y[2];
  int a,b;
  scanf("%s%s",x,y);
  a=judge(x[0]);
  b=judge(y[0]);
  if(a<b) printf("<\n");
  if(a==b) printf("=\n");
  if(a>b) printf(">\n");
  return(0);
}
