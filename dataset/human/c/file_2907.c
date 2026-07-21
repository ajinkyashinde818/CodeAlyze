#include <stdio.h>
 
int main(void){
  int K, S, count, i, j, k;
  scanf("%d", &K);
  scanf("%d", &S);
  for(i=0; i<=K; i++){
    for(j=0; j<=K; j++){
      if(i+j<=S && S-i-j <= K) count++;
    }
  }
  printf("%d", count);
}
