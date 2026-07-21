#include <stdio.h>
#define MAX (2*100000)

int main()
{
  int K;
  int N;
  int A[MAX];
  int i;
  int max = -1;
  int length;
  scanf("%d %d", &K, &N);
  for(i = 0; i < N; ++i)
    scanf("%d", &A[i]);
  --i;
  
  for(/*blank*/; i >= 0; --i){
    if(i == 0)
      length = A[0] + (K - A[N - 1]);
    else
      length = A[i] - A[i - 1];
    if(max < length)
      max = length;
  }
  printf("%d\n", K - max);
  return 0;
}
