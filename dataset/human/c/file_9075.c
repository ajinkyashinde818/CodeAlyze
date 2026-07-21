#include <stdio.h>
int main(){
    
  int N=0;
  int K=0;
  int count=0;
  
  scanf("%d",&N);
  scanf("%d",&K);
  
  int h[N];
  
  for(int i=0;i<N;i++){
      scanf("%d",&h[i]);
  }
  
  for(int i=0;i<N;i++){
      if(K<=h[i]){
          count = count +1;
      }
  }
  
  printf("%d",count);
  
  return 0;
}
