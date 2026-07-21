#include <stdio.h>

int main(void){
  int A,B,C,D,ab,cd,max;
  scanf("%d¥n",&A);
  scanf("%d¥n",&B);
  scanf("%d¥n",&C);
  scanf("%d¥n",&D);
  ab = A*B;
  cd = C*D;
  if(ab<=cd){
    max = cd;
  }else if(ab>cd){
    max = ab;
  }
  printf("%d",max);
  return 0;
}
