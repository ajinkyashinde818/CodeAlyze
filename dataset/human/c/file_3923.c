#include<stdio.h>

int main(){
  int A, B, K;
  scanf("%d %d %d", &A, &B, &K);

  int G;

  while(A != 0 && B != 0){
    if(A == 1 || B == 1) break;

    if(A >= B) A = A % B;
    else B = B % A;
  }

  if(A == 0) G = B;
  else if(B == 0) G = A;
  else G = 1;

  int i = 0;
  int j = 1;
  int L[K];
  while(i < K){
    if(G % j == 0){
      L[i] = G / j;
      i++;
    }
    j++;
  }

  printf("%d\n", L[K-1]);


  return 0;
}
