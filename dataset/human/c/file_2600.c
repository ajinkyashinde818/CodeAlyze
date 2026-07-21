#include<stdio.h>

int main(void)
{
  int i,fraga = 0,fragb=0,fragc=0;
  char str[4];
  scanf("%s",str);
  for(i=0;i<3;i++)
    {
      if(str[i] == 'a')
	{
	  fraga++;
	}
      else if(str[i] == 'b')
	{
	  fragb++;
	}
      else if(str[i] == 'c')
	{
	  fragc++;
	}
    }
  if(fraga != 0 && fragb != 0 && fragc != 0)
    {
      printf("Yes\n");
    }
  else
    {
      printf("No\n");
    }
  return 0;
}
