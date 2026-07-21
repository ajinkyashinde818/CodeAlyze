#include <stdio.h>

int main(void){
  int R, G, B, N;
  int i=0, j=0, ans=0;
  
  scanf("%d %d %d %d",&R ,&G, &B, &N);
  
  for(i=0; i <= N/R; i++){
    for(j=0; j <= (N-R*i)/G; j++){
      if((N-R*i-G*j)%B == 0){
        ans +=1;
      }
    }
  }
  printf("%d",ans);
  return 0;
}
