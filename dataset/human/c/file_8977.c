#include <stdio.h>
int main(void)
{
  int n;
  int count=0;

  while(1)
    {
      scanf("%d",&n);
      if(n == 0) break;
      while(n != 1)
	{
	  if(n % 2 == 0)
	    {
	      n /= 2;
	      count++;
	    }
	  else if(n % 2 == 1)
	    {
	      n = n * 3 + 1;
	      count++;
	    }
	}
      printf("%d\n",count);
      count = 0;
    }
  return 0;
}
