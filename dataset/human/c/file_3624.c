#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

long long cmn(long long a, long long b){
  long long maxval = fmax(a, b);
  long long minval = fmin(a, b);
  if (minval==0){
    return maxval;
  }
  long long amari = maxval%minval;
  return cmn(minval, amari);
}

int main(){
  long long A, B;
  scanf("%lld",&A);
  scanf("%lld",&B);
  long long cmnval = cmn(A, B);
  //printf("cmnval=%lld\n", cmnval);
  long long ans = (long long)A/cmnval;
  ans *= B;
  printf("%lld\n", ans);
  return 0;
}
