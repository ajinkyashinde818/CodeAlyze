#include <stdio.h>
#include <stdlib.h>

int main()
{
  long sum = 0;
  long long dif, tmp;
  int N;
  scanf("%d", &N);
  int a[N];
  for(int i = 0; i < N; i++){
    scanf("%d", &a[i]);
    sum += a[i];
  }

  long long up;
  up = a[0];
  dif = labs(2*up - sum);

  for(int i = 1; i < N-1; i++){
    up += a[i];
    tmp = labs(2*up - sum);
    if(tmp < dif) dif = tmp;
  }
  printf("%lld", dif); 
  return 0;
}
