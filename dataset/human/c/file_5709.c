#include <stdio.h>

int main(void){
  int i = 0;
  int n = 0;
  int min;
  int now;
  int max_margin = -2147483648;
  int margin;

  scanf("%d", &n);
  scanf("%d", &min);
  for(i = 1; i < n; i++){
    scanf("%d", &now);
    margin = now - min;
    if(margin > max_margin){
      max_margin = margin;
    }
    if(now < min){
      min = now;
    }
  }
  printf("%d\n", max_margin);

  return 0;
}
