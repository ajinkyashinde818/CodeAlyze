#include <stdio.h>

int	main(void)
{
  	int	N;
  	int	A[21];
  	int	B[21];
  	int	C[21];
	int	num;
  	int	i;
  	int	sum;
  	int pre;
  
  	num = scanf("%d\n", &N);
  	if (num != 1)
      	return (0);
  
    A[0] = 0;
  	for (i=1; i<=N; i++)
    {
      	num = scanf("%d", &A[i]);
      	if (num != 1)
          	return (0);
    }
  	
  	B[0] = 0;
    for (i=1; i<=N; i++)
    {
      	num = scanf("%d", &B[i]);
      	if (num != 1)
          	return (0);
    }
  	
  	C[0] = 0;
  	for (i=1; i<=N-1; i++)
    {
      	num = scanf("%d", &C[i]);
      	if (num != 1)
          	return (0);
    }
  	
  	pre = 0;
  	sum = 0;
  	for (i=1; i<=N; i++)
    {
      	sum += B[A[i]];
      	if (pre == A[i] - 1)
          	sum += C[A[i] - 1];
        pre = A[i];
    }
  	
  	printf("%d", sum);
  	return (0);
}
