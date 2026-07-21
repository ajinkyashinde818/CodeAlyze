#include <stdio.h>

int main(void){
  char A, B;
  scanf("%c %c\n", &A, &B);
  A = (int)A;
  B = (int)B;
  if (A - B > 0) printf(">\n");
  else if(A - B < 0) printf("<\n");
  else printf("=\n");
  return 0;
}
