#include<stdio.h>

#define N 200000

int Calc_max_marge(int *,int);

int main(void){
  int A[N],num;
  int i;

  scanf(" %d",&num);
  for(i = 0; i < num; i++){
    scanf(" %d",&A[i]);
  }

  printf("%d\n",Calc_max_marge(A,num));
  
  return 0;
}

int Calc_max_marge(int *A,int num){
  int i;
  int min,max=A[1]-A[0];

  min = A[0];

  for(i = 1; i < num; i++){
    max = max > A[i]-min ? max : A[i]-min;
    min = min < A[i] ? min : A[i];
  }

  return max;
}
