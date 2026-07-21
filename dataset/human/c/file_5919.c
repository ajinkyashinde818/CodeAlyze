#include<stdio.h>
#include<stdlib.h>

int main(void){
  int N,i,min,max;
  int *F;
  
  while(1){
  scanf("%d",&N);
  
  if(N>=2 && N<=200000)break;
  }
    F = (int*)malloc(sizeof(int)*N);
  for(i=0;i<N;i++){
    while(1){
      scanf("%d",&F[i]);
      if(F[i]>=1 && F[i]<=1000000000)break;
    }
  }
  
  min=F[0];
  max=F[1]-min;
  
  for(i=1;i<N;i++){
    if(max<F[i]-min)max=F[i]-min;
    if(min>F[i])min=F[i];
  }
  printf("%d\n",max);
  free(F);
  
  return 0;
}
