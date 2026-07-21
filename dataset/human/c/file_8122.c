#include<stdio.h>
#include<stdlib.h>
int main(){
  int a,b,c,d,s1,s2;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  s1=a*b;
  s2=c*d;
  if(s1>=s2){printf("%d",s1);}else{
    printf("%d",s2);
  }
  return 0;
}
