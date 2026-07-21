#include <stdio.h>

int main(void){
  int x;
  int num[10000];
  for(x= 0;x < 10000;x++){
    scanf("%d", &num[x]);
    if(num[x] == 0) break;
  }
  for(x= 1;x <= 10000;x++){
    if(num[x-1] == 0) break;   
    printf("Case %d: %d\n", x, num[x-1]);
  }
  return 0;
}
