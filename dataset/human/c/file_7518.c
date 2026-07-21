#include <stdio.h>

int main() {

  int i, x[10001];
  i = 0;
  while(1) {
    scanf("%d", &x[i]);
    if ( x[i] == 0 )
      break;
    i++;
  }
  
  i = 0;
  while(1) {
    if ( x[i] == 0 )
      break;
    printf("Case %d: %d\n", i + 1, x[i]);
    i++;
  }

  return 0;

}
