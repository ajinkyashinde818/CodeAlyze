#include <stdio.h>


int main() {
    long a, b, x, tmp,r;
    scanf("%ld %ld", &a, &b);
    x = a * b;
 
  /* 自然数 a > b を確認・入替 */
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }

  printf("%ld", x/b);
}
