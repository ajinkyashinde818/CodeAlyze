#include <stdio.h>
#include <stdlib.h>

long long min(long long a,long long b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  long N;
  long long sum = 0,x = 0;
  long long ans = 10000000000000000;
  scanf("%ld",&N);

  long long a[N];

  for(int i = 0;i < N;i++){
    scanf("%lld",&a[i]);
    sum += a[i];
  }

  for(int i = 0;i < N-1;i++){
    x += a[i];
    ans = min(ans,llabs(sum-2*x));
  }

  printf("%lld\n",ans);

  return 0;
}
