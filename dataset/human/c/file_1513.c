#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
  char X, Y;

  scanf("%c %c", &X, &Y);
  X -= 'A';
  Y -= 'A';
  
  if(X > Y){
    printf(">");
  }else if(X == Y){
    printf("=");
  }else{
    printf("<");
  }

  printf("\n");

  return 0;
}
