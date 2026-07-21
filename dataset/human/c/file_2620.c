#include<stdio.h>

int main()
{
  char s[4];
  
  scanf("%s",s);
  
  int i;
  
  int count[3]={};
  
  for(i=0;i<3;i++)
  {
    if(s[i]=='a')
    {
      count[0]++;
    }
    else if(s[i]=='b')
    {
      count[1]++;
    }
    else if(s[i]=='c')
    {
      count[2]++;
    }
  }
  
  for(i=0;i<3;i++)
  {
    if(count[i]!=1)
    {
      printf("No\n");
      return 0;
    }
  }
  
  printf("Yes\n");
  
  return 0;
}
