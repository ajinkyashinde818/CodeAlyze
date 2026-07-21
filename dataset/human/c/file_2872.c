#include <stdio.h>

int main(void) {
  int K, S;
  scanf("%d %d", &K, &S);

  int ANS = 0;
  for(int x = 0; x <= K; x++) {
    for(int y = 0; y <= K; y++) {
      int z = S - x - y;
      if(0 <= z && z <= K)
	ANS++;
    }
  }
  printf("%d\n", ANS);
  return 0;
}
