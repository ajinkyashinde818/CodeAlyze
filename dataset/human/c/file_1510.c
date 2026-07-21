#include<stdio.h>
int main(){
  int unused __attribute__((unused));
  char X, Y;
  unused = scanf("%c %c", &X, &Y);

  if((int)X < (int)Y) printf("<");
  else if((int)X > (int)Y) printf(">");
  else printf("=");

  return 0;
}
