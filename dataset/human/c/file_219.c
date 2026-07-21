#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N;
  scanf("%d",&N);

  int A[N];
  int cnt = 0;
  int MIN = 1e9;
  long long ans = 0;
  for(int i = 0;i < N;i++){
    scanf("%d",&A[i]);
    if(A[i] < 0) cnt++;
    MIN = min(MIN,abs(A[i]));
    ans += abs(A[i]);
  }

  if(cnt%2 == 0) MIN = 0;
  else MIN *= 2;
  printf("%lld\n",ans-MIN);


  return 0;
}
