#include <stdio.h>

int		main(void)
{
  	int		N;
  	int		R;
  	int		num;
  
  	num = scanf("%d %d", &N, &R);
  	if (num != 2)
    {
      	return (0);
    }
  
  	if (N < 10 && N > 0)
      	printf("%d", R + 100 * (10 - N));
  	else
      	printf("%d", R);
  	return (0);
}
