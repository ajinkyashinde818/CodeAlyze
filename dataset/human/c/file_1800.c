#include<stdio.h>

int main(void){
  int N;
  scanf("%d",&N);
  int A[N],B[N],C[N - 1];
  for(int i = 0;i < N;i++)
    scanf("%d",&A[i]);  
  for(int i = 0;i < N;i++)
    scanf("%d",&B[i]);
  for(int i = 0;i < N - 1;i++)
    scanf("%d",&C[i]);
  int sum = 0;
  for(int i = 0;i < N;i++){
    sum += B[A[i] - 1];
    if(A[i + 1] == A[i] + 1)
      sum += C[A[i] - 1];    
  }
  printf("%d",sum);
  return 0;
}
