#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
  	int	N;
  	int	K;
  	int	A[200001];
  	int	B[200001];
	int	num;
  	int	i;
  	int	max;
  	int	tmp;
  
  	num = scanf("%d %d\n", &K, &N);
  	if (num != 2)
      	return (0);

  	for (i=0; i<N; i++)
  	{
      	num = scanf("%d", &A[i]);
  	}

  	for (i=0; i<N; i++)
    {
      	B[i] = A[(i+1) % N] - A[i % N];
      	if (B[i] < 0)
      	{
          	B[i] = B[i] + K;
      	}
    }

  	max = 0;
  	tmp = 0;
  	for (i=0; i<N; i++)
    {
      	if (max < B[i])
        {
          	max = B[i];
      		tmp = i;
        }
    }
  
  	printf("%d", K - max);
  	return (0);
}
