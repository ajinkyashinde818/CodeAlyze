#include <stdio.h>
#include <stdlib.h>

int main(void){
  int M,N;
  
  scanf("%d %d",&N,&M);  
  if(N<M){
    printf("error\n");
    exit(1);
  }
  
  if(M==N){
    printf("Yes\n");
  }
  else{
    printf("No\n");
  }
  return 0;
}
