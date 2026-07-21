#include <stdio.h>
int main()
{
  long long int N, K, S;
  scanf("%lld %lld %lld", &N, &K, &S);
  
  long long int i;
  
  long long int T;
  if(S == 1000000000) T=S-1;
  else T=S+1;
  for(i=0; i<N; i++){
    if(i<K)  printf("%d ", S);
    else printf("%d ", T);
  }
}
