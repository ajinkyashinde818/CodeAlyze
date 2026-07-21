#include "stdio.h"

int main(int argc, char const *argv[]) {
  int i,A,B,K;
  scanf("%d%d%d",&A,&B,&K);
  int N=0;
  int X[200];
  for (i = 1; i < 101; i++) {
    if (A%i==0 && B%i==0) {
      X[N]=i;
      N++;
    }
  }
  printf("%d", X[N-K]);
  return 0;
}
