#include <stdio.h>

int main(void)
{
  int N, D, X, ans;
  scanf("%d%d%d", &N, &D, &X);
  ans = N+X;
  for(int i = 0; i < N; i++){
    int A;
    scanf("%d", &A);
    ans += (D-1)/A;
  }
  printf("%d\n", ans);  
}
