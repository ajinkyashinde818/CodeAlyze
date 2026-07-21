#include <stdio.h>
int min(int A, int B) {
  if (A < B) {
    return A;
  } else {
    return B;
  }
}

int main() {
  int A;
  int B;
  int K;
  scanf("%d %d %d",&A, &B, &K);
  int i;
  int count = 0;
  for (i = min(A,B); i > 0; --i) {
    if (A%i == 0 && B%i == 0) {
      ++count;
      if (count == K) {
        break;
      }
    }
  }
  printf("%d\n",i);
  return 0;
}
