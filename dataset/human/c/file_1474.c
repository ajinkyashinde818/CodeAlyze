#include<stdio.h>
int main(void)
{
  int i,count=0;
  char str[4];
  
  fgets(str,sizeof(str),stdin);
  
  for(i=0;i<2;i++)
  {
    if(str[i] == '9')
      count++;
  }
  
  if(count>0)
  {
    puts("Yes");
  }else
  {
    puts("No");
  }
  
  return 0;
}
