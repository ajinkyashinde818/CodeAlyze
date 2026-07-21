#include <stdio.h>
 
int main(void){
  int result = 0;
  int R,G,B,N;
  scanf("%d %d %d %d", &R, &G, &B, &N);
  
  for(int r = 0; r <= N/R; r ++){
    for(int g = 0; g <= (N-R*r)/G; g ++){
      if ((N-R*r-G*g)%B == 0){
        result ++;
      }
    }
  }
  printf("%d", result);
  return 0;
}
