#include <stdio.h>
#include <stdlib.h>

int main(void){

  char  *s;
  int   n, k, i;

  scanf("%d", &n);
  s = malloc(n * sizeof(s));
  scanf("%s", s);
  scanf("%d", &k);

  for (i = 0; i < n; i++) {
    if (s[i] != s[k - 1]) {
      s[i] = '*';
    }
  }

  printf(s);

  return 0;

}
