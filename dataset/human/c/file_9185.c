#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int n, k, i, h, cou=0;
  scanf("%d %d", &n, &k);
  for(i=0; i < n; i++){
    scanf(" %d", &h);
    if(h >= k) cou++;
  }
  printf("%d", cou);
}
