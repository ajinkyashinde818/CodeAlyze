#include <stdio.h>

int	main(void)
{
  	int	N;
  	int	K;
  	int	h[100001];
 	int	num;
  	int	i;
  	int count;
  
  	num = scanf("%d %d", &N, &K);
  	if (num != 2)
      	return (0);
  	
  	count = 0;
  	for (i=1; i<=N; i++)
    {
      	num = scanf("%d", &h[i]);
      	if (num != 1)
          	return (0);
      	if (h[i] >= K)
          	count++;
    }
  
  	printf("%d", count);
  	return (0);
}
