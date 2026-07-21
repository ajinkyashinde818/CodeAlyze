#include <stdio.h>

int main(void){
  int n, i;
  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++) scanf("%d", &a[i]);
  int num = 0;
  int count = 0;
  i = 0;
  while(num < n){
    count = a[i];
    if(count == 2){
      num++;
      printf("%d\n", num);
      break;
    }else{
      i = count - 1;
      num++;
    }
    if(num == n) printf("-1\n");
  }
  return 0;
}
