#include <stdio.h>

int main()
{
  int n, k;
  char s[11];
  scanf("%d", &n);
  scanf("%s", &s);
  scanf("%d", &k);
  int i;
  char c = s[k - 1];
  for (i = 0; i < n; i++) {
    if (s[i] != c)
      s[i] = '*';
  }
  printf("%s", s);
  return 0;
}
