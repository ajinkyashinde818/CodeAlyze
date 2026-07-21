#include<stdio.h>
int main(void)
{
  int a,b,c,d;
  char str[32];
  fgets(str,sizeof(str),stdin);
  sscanf(str,"%d%d%d%d",&a,&b,&c,&d);
  if((a*b) > (c*d))
  {
    printf("%d\n",a*b);
  }
  else
  {
    printf("%d\n",c*d);
  }
  return 0;
}
