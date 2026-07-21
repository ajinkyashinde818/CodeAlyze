#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
  int n, k, i, a, p = 0;
  int max = 0;
  scanf("%d%d", &k, &n);
  int *S, *s;
  S = (int *)malloc(sizeof(int) * (n + 1));
  s = (int *)malloc(sizeof(int) * (n + 1));
  scanf("%d", &a);
  S[0] = a;
  for (i = 1; i < n; i++)
  {
    scanf("%d", &a);
    S[i] = a;
    s[i - 1] = a - S[i - 1];
    if (s[i - 1] > max)
    {
      max = s[i - 1];
      p = i - 1;
    }
  }
  s[i] = k - S[n - 1] + S[0];
  if (s[i] > max)
  {
    printf("%d\n", S[n - 1] - S[0]);
    return 0;
  }
  printf("%d\n", S[p] + k - S[p + 1]);

  return 0;
}
