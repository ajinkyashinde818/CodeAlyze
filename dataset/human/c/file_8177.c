#include <stdio.h>

int main(){

  int a,b,c,d,l1,l2;

  scanf("%d %d %d %d",&a,&b,&c,&d);

  l1=a*b;
  l2=c*d;

  if(l1<l2) printf("%d\n",l2);
  if(l2<l1) printf("%d\n",l1);
  if(l1==l2) printf("%d\n",l1);

  return 0;
}
