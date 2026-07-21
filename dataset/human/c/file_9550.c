#include<stdio.h>
int main(){
  int a,b,c,d,e=0;
  scanf("%d %d %d",&a,&b,&c);
  e+=a+c;
  b--;
  for(int i=0; i<a; i++){
    scanf("%d",&d);
    e+=b/d;
  }
  printf("%d",e);
  return 0;}
