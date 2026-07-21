#include <stdio.h>
int main()
{
	int N;
	int R;
	scanf("%d %d",&N,&R);
  	if ((N >= 1 && N < 10) && (R <= 4111 && R >= 0))
    {
      printf("%d",R + (100 * (10 - N)));
    }
  	else if ((N >= 10 && N <= 100) && (R <= 4111 && R >= 0))
    {
      printf("%d",R);
    }
  	return (0);
  
}
