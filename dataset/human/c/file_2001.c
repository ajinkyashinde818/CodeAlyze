#include<stdio.h>

int main(){
  long d_p, d_m, n_m;
  scanf("%ld %ld %ld", &n_m, &d_m, &d_p);

  long del;

  if(d_p <= d_m + n_m + 1) del = d_p + d_m;
  else del = 2 * d_m + n_m + 1;;

  printf("%ld\n", del);

  return 0;
}
