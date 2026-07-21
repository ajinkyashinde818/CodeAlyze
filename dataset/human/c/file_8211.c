#include<stdio.h>

int main(){
  int A, B, C, D;//入力される値
  int S1, S2;//面積
  int max;
  scanf("%d %d %d %d", &A, &B, &C, &D);
  S1 = A*B;
  S2 = C*D;
  if(S1 > S2){
    max = S1;
  }else{
    max = S2;
  }
  printf("%d\n", max);
  return 0;
}
