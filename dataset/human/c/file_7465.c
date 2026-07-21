#include <stdio.h>

int main(){
  int i;
  int num[10000];
  for(i = 0;i < 10000;i++){
    scanf("%d", &num[i]);
    if(num[i] == 0) break;
  }
  for(i = 1;i <= 10000;i++){
    if(num[i-1] == 0) break;   
    printf("Case %d: %d\n", i, num[i-1]);
  }
  return 0;
}
