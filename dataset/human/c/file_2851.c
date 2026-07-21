#include <stdio.h>
#include <math.h>

int main(void){
  int K,S;
  int X,Y;
  scanf("%d%d", &K,&S);


  int count = 0;

  for (X = 0; X <= K; X++) {
    for (Y = 0; Y <= K; Y++) {
      int Z = S - X - Y;
      if (0 <= Z && Z <= K) {
        count++;
      }
    }
  }

  printf("%d\n", count);
}
