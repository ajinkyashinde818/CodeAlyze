#include <stdio.h>

int main(){
  int K, S;
  int count = 0;
  int Z;

  scanf("%d %d", &K, &S);

  for(int X = 0; X <= K; X++){
    for(int Y = 0; Y <= K; Y++){

      Z = S - (X + Y);
      if(Z >= 0 && Z <= K){
        count++;
      }

    }
  }

  printf("%d\n", count);

  return 0;
}
