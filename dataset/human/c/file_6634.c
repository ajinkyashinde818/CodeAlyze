#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i, n, t, min;
  long differ=-10000000000;

  scanf("%d", &n);
  
  for( i=0; i<n; i++ )
    {
      scanf("%d", &t);
      if( i == 0 )
	{
	  min = t;
	  continue;
	}
      
      if( differ < t - min ) differ = t - min;
      
      if( t < min ) min = t;	
      
    }
  
  printf("%d\n", differ);
  
  return 0;
}
