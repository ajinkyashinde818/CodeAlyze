#include <stdio.h>

int main(void)
{
  int x[10000] = {0};
  int i = 0;
  int j = 0;
  
  do {
   scanf("%d", &x[i]);
   i++;
  } while(x[i - 1]);

  j = i;

  for(i = 0; i < j - 1; i++)
    printf("Case %d: %d\n", i + 1, x[i]);
	
  return 0;
}
