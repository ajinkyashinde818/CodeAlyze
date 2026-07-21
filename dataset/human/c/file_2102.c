#include <stdio.h>

int main(void){
  long int N; // 入力された数
  scanf("%ld", &N);
  
  if (N%2 == 1) {
    printf("0\n");
    return 0;
  }
  
  long int ans = 0; // Nの素因数5の数
  long int N_tens = N / 10; // 1からNまでに何個の10, 20, 30・・・があるか
  ans += N_tens;
  
  while(N_tens!=0){
    ans += N_tens / 5;
    N_tens /= 5;
  }
  
  printf("%ld", ans);
}
