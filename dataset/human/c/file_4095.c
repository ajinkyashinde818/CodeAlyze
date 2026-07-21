#include <stdio.h>
int main(void)
{
  int A, B, K, a, ans, i=0;
  scanf("%d %d %d", &A, &B, &K);
  for(a=A; a>0; a--){
    if(A%a==0){
      if(B%a==0){
        ans = a;
        i++;
      }
    }
    if(i==K){
    break;
    }
  }
  printf("%d", ans);
  return 0;
}
