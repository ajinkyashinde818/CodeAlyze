#include <stdio.h>
 
int main()
{
  int N;
  scanf("%d", &N);

  int A[21];
  for (int i=1; i<=N; i++) scanf("%d", A+i);

  int B[21];
  for (int i=1; i<=N; i++) scanf("%d", B+i);

  int C[20];
  for (int i=1; i<N; i++) scanf("%d", C+i);

  int ret = 0;
  for(int i=1; i<=N; i++)
  {
    ret += B[A[i]];
    if (i!=1 && A[i-1] == A[i]-1) ret += C[A[i-1]];
  }
    
  printf("%d\n", ret);
  return 0;  
}
