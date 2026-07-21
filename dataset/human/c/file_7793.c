#include <stdio.h>
  
 int main(void){
 
      int i,N;
 
      scanf("%d",&N);
 
      int K[N];
      int P[N];
      for(i=0; i<N; i++){
          scanf("%d %d",&K[i],&P[i]);
          }
 
 
      for(i=0; i<N; i++){
          if(K[i]%P[i]==0)
          printf("%d\n",P[i]);
          else
          printf("%d\n",K[i]%P[i]);
          }
      return 0;
  }
