#include <stdio.h>

int main(void){
  int n, ans, count;

  scanf("%d", &n);
  while(n != 0){
    ans = n;
    count = 0;
    while(ans != 1){
      count++;
      if(ans % 2 == 1){
        ans = ans * 3 + 1;
      }else{
        ans /= 2;
      }
    }
    printf("%d\n", count);
    scanf("%d", &n);
  }
  return 0;
}
