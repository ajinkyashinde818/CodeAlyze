#include <stdio.h>

int main()
{
  int K, S;
  int X, Y, Z;
  int i, j, k;
  int ans = 0;

  scanf("%d %d", &K, &S);

  for(i = 0; i <= K; i++) {
    for(j = 0; j <= K; j++) {
      if(S-i-j <= K && S-i-j >= 0) {
	ans++;
      }
    }
  }

  printf("%d\n", ans);
  
  return 0;
}
