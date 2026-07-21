#include<stdio.h>

int main(){
  int i,N,key,max=-99999,min;
  int x=0;
  int A[200001];

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  max=A[1]-A[0];
  min=A[0];
  
  for(i=1;i<N;i++){
    if(min>A[i]){
      min=A[i];
      continue;
    }
    if(A[i]<=A[i+1]) continue;
    if(A[i]-min>max) max=A[i]-min;
  }
 
  printf("%d\n",max);
    
  return 0;
}
