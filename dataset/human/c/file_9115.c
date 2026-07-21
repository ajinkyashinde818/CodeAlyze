#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int n, k, c, t;
int main(void){
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i){
    scanf("%d", &t);
    if (t >= k) ++c;
  }
  printf("%d", c);
  return 0*printf("\n");
}
