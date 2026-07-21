#include<stdio.h>

int main(){
  long int N;
  long int A[111111],B[111111];
  scanf("%ld",&N);
  long int i;
  for(i=0;i<=N-1;i++)
    scanf("%ld",&A[i]);
  long int count = 0;
  for(i=0;i<=N-1;i++){
    if(A[i] < 0){
      B[i] = - A[i];
      count++;
      };
    if(A[i] >= 0) B[i] = A[i];
    };
  long int min = B[0];
  for(i=1;i<=N-1;i++)
    if(min > B[i]) min = B[i];
  long int sum = 0;
  for(i=0;i<=N-1;i++)
    sum += B[i];
  if(count % 2 == 1)
    sum = sum - 2 * min;
  printf("%ld",sum);
}
