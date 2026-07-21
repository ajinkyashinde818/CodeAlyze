#include <stdio.h>
int main(void)
{
  char s[3]={};
  int i,fa=0,fb=0,fc=0;
  scanf("%s",s);
  for(i=0;i<3;i++)
  {
    if(s[i]=='a')
    {
      fa=1;
    }
    if(s[i]=='b')
    {
      fb=1;
    }
    if(s[i]=='c')
    {
      fc=1;
    }
  }
  if(fa==1 && fb==1 && fc==1)
  {
    printf("Yes\n");
  }
  else
  {
    printf("No\n");
  }
  return 0;
}
