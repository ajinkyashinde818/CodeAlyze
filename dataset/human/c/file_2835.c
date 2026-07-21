#include <stdio.h>

int main(void){
  int K, S, i, j, count = 0;
  scanf("%d %d", &K, &S);
  for(i=0; i <= K; i++){
    for(j=0; j <= K; j++){
      if(0 <= S - i - j && S - i - j <= K)
        count++;
    }
  }
  printf("%d",count);
  return 0;
}
