#include<stdio.h>
int main(void)
{
 	int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  if(a*b<c*d) printf("%d\n",c*d);
  else if(a*b>c*d) printf("%d\n",a*b);
  else if(a*b==c*d) printf("%d\n",a*b);
  return 0;
}
