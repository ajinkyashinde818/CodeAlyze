#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

int main(){
  long long N;
  scanf("%lld",&N);
  long long ans = 0;
  long long i = 1;
  if (N%2==1){
    printf("0\n");
  } else {
    long long power = 10;
    while(N>=power){
      //printf("power=%lld\n",power);
      ans += (long long)(N/power);
      //      printf("ans=%lld\n", ans);
      power *= 5;
      i++;
    }
    printf("%lld\n",ans);
  }
  return 0;
}
