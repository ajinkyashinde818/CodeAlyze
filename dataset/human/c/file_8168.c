#include<stdio.h>
int max(int a,int b){
  if(a>b) return a;
  else return b;
}
int main(void){
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  printf("%d\n",max(a*b,c*d));
  return 0;
}
