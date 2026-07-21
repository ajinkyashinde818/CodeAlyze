#include<stdio.h>

int main(void)
{
  int a,b,c,d,ans1,ans2,ans;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ans1=a*b;
  ans2=c*d;
  if(ans1>ans2)
   ans=ans1;
  else
   ans=ans2;
  printf("%d\n",ans);
  return 0;
}
