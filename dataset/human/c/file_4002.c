#include <stdio.h>

int main(void) {
  int A, B, K;
  scanf("%d%d%d", &A, &B, &K);

  int Min = (A > B) ? B : A;
  int Num = 0;
  for(int i = Min; i > 0; i--) {
    if((A % i == 0) && (B % i == 0)) {
      Num++;
      if(Num == K) {
	printf("%d\n", i);
      }
    }
  }

  return 0;
}
