#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int  m, n;
  char str_n[6];
  char str_m[6];
  
  scanf("%s", str_n);
  scanf("%s", str_m);
  n = atoi(str_n);
  m = atoi(str_m);
  if(n == m) {
    printf("Yes");
  } else {
    printf("No");
  }
  
  return 0;
}
