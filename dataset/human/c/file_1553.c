#include <stdio.h>

int main(void){
  char x[2], y[2];

  scanf("%s", x);
  scanf("%s", y);

  if(x[0] < y[0]) printf("<");
  if(x[0] > y[0]) printf(">");
  if(x[0] == y[0]) printf("=");
  return 0;
}
