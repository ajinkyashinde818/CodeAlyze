#include<stdio.h>
int main(){
  int N;
  
  scanf("%d",&N);
  
  int A[N];
  int B[N];
  int C[N-1];
  int total=0;
  
    
  
  for(int i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&B[i]);
  }
  for(int i=0;i<N-1;i++){
    scanf("%d",&C[i]);
  }
  for(int i=0;i<N;i++){
    total=total+B[i];
  }
  for(int i=0;i<N-1;i++){
    if(A[i+1]==A[i]+1){
      total=total+C[A[i]-1];
    }
  }
  
  printf("%d\n",total);
  
  
  return 0;
}
