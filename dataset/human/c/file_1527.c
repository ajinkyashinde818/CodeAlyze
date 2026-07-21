#include <stdio.h>

int main(void){
  char x,y;
  int a,b;
  scanf("%c %c", &x, &y);
  a = x - '0';
  b = y - '0';
  if(a == b){
    printf("=\n");
  }else if(a > b){
    printf(">\n");
  }else{
    printf("<\n");
  }
  return 0;
}
