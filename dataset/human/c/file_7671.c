#include <stdio.h>

int main (void){
  int a[10000];
  int i = 0;

  while(1){
    scanf("%d", &a[i]);
    if(a[i] == 0) {
      break;
    }
    i++;
  }

  for(i = 0; a[i] != 0; i++){
    printf("Case %d: %d\n", i + 1, a[i]);
  }

  return 0;
}
