#include <stdio.h>

int main(void) {
  int R,G,B,N;
  scanf("%d%d%d%d", &R, &G, &B, &N);

  int X = 0;
  for(int i = 0; i <= N; i+=R) {
    for(int j = 0; j <= N; j+=G) {
      int Y = N - (i + j);
      if(Y < 0) {
	break;
      } else if(Y == 0) {
	X++;
      } else {
	if((Y % B) == 0) {
	  X++;
	}
      }
      //printf("R=%d G=%d B=%d\n", i, j, Y);
    }
  }

  printf("%d\n", X);
  return 0;
}
