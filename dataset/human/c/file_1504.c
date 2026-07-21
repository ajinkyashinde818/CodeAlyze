#include<stdio.h>
int main(void)
{
  int ope;
  char str[8];
    
  fgets(str,sizeof(str),stdin);
  
  ope = str[0] - str[2];
  
  if(ope > 0)
  {
    puts(">");
  }else if(ope == 0)
  {
    puts("=");
  }else
  {
    puts("<");
  }
  return 0;
}
