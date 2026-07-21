#include <stdio.h>

int main(void){
  int i, x[10000], n;

  i = 1;
  while(1){
    scanf("%d", &x[i]);
    if (x[i] == 0){
      break;
    }
    i++;
  }

  n = i;
  for (i = 1; i < n; i++){
    printf("Case %d: %d\n", i, x[i]);
  }

  return 0;
}
