#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i,j,N;
  int R[2000000];
  int maxv=-1000000000,minv;

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    /* code */
    scanf("%d", &R[i]);
  }

  minv=R[0];

    for (j = 1; j <= N-1; j++) {
      /* code */
          if(maxv < R[j]-minv){
            maxv=R[j]-minv;
          }
          if (minv>R[j]) {
            /* code */
            minv=R[j];
          }
    }


  printf("%d\n", maxv);
  return 0;
}
