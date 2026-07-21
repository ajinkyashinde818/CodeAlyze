#include <stdio.h>
int main(void)
{
  int a,b,c,d,s1,s2,ans;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  s1=a*b;
  s2=c*d;
  if(s1>s2)
  {
    ans=s1;
  }
  else
  {
    ans=s2;
  }
  printf("%d\n",ans);
  return 0;
}
