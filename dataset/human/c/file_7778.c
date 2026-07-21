#include<stdio.h>


int main(){

  int N, i, K, P, W;

  scanf("%d", &N);

  for(i=0;i < N;i++){

    scanf("%d %d", &K, &P);

    if(K > P){

      W = K % P;

      if(W != 0)

	printf("%d\n", W);

      else

	printf("%d\n", P);
      
    }else
      
      printf("%d\n", K);

    
  }
    

  return 0;
  
}
