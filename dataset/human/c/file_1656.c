#include <stdio.h>
int main(void){
  int n, x, y = -1;
  int i;
  int sum = 0;
  scanf("%d",&n);

  int a[20], b[20], c[20];
  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  for(i = 0; i < n; i++){
    scanf("%d",&b[i]);
  }
  for(i = 0; i < n - 1; i++){
    scanf("%d",&c[i]);
  }
  for(i = 0; i < n; i++){
    x = a[i];
    sum = sum + b[x - 1];
    if(x == y + 1){
      sum = sum + c[x - 2];
    }
    y = x;
  }
  printf("%d",sum);
  return 0;
}
