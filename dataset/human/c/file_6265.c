#include <stdio.h>
#include <math.h>
 
int main(){
 
  int i, n, input, max, min;
 
  scanf("%d", &n);
  scanf("%d", &input);
 
  max = -1000000000;
  min = input;
  for(i = 1; i <= n-1; i++){
    scanf("%d", &input);
    max = fmax(max, input-min);
    min = fmin(min, input);
  }
  printf("%d\n", max);
 
  return 0;
}
