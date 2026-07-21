#include <stdio.h>

#include <stdlib.h>

long abs_l(long i){
  if(i < 0)
    return -1 * i;

  return i;
}

int main(void){
  int *c;
  int n;
  scanf("%d",&n);

  c = (int*)malloc(sizeof(int) * n);

  long sum = 0;
  int i;
  for(i = 0; i < n;i++){
    scanf("%d",&c[i]);
    sum += c[i];
  }

  long res = abs_l(c[0] - (sum - c[0]));
  long sunuke = 0;
  for(i = 0; i < n - 1;i++){
    sunuke += c[i];
    sum -= c[i];
    if(abs_l(sunuke - sum) < res)
      res = abs_l(sunuke - sum);
  }

  printf("%ld\n",res);

  free(c);
  return 0;
}
