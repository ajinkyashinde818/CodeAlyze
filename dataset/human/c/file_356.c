#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comp(const void *a, const void *b){return *(int*)a-*(int*)b;}
int main(void){
  int n, r;
  scanf("%d%d", &n, &r);
  printf("%d\n", n>=10?r:r+100*(10-n));
}
