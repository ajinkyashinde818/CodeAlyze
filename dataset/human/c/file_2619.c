#include<stdio.h>
int main(void)
{
  int i,a=0,b=0,c=0;
  char str[8];
  
  fgets(str,sizeof(str),stdin);
  
  for(i=0;i<3;i++)
  {
    switch (str[i])
    {
      case 'a': a++;
    			continue;
      case 'b': b++;
                continue;
      case 'c': c++;
                continue;
    }
  }
  
  if(a*b*c == 1)
  {
    puts("Yes");
  }else
  {
    puts("No");
  }
  
  return 0;
}
