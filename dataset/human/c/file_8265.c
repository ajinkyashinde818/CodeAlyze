#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);
  char S[11];
  scanf("%s", S);
  int K;
  scanf("%d", &K);

  for(int i = 0; i < N; i++) {
    if((i != (K-1)) && (S[K-1] != S[i])) {
      S[i] = '*';
    }
  }
  printf("%s\n", S);
  return 0;
}
