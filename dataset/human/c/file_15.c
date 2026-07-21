#include <stdio.h>
int main(void){
  int r, g, b, n, count = 0;
  scanf("%d %d %d %d", &r, &g, &b, &n);
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(n - i * r - j * g >= 0 && (n - i * r - j * g) % b == 0){
        count++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
