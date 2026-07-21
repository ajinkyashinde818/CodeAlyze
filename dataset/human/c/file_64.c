#include<stdio.h>

int main(void){
  int R, G, B, N;
  scanf("%d %d %d %d", &R , &G , &B , &N);

  int count = 0;
  for(int r = 0 ; r <= 3000 ; r++){
    for(int g = 0 ; g <= 3000 ; g++){

      int v = r*R + g*G;
      if(N >= v && (N - v) % B == 0)   count++;

    }
  }

  printf("%d", count);

return 0;
}
