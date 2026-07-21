#include <stdio.h>

int main() {
  long int a, b, ans;
  scanf("%ld %ld", &a, &b);
  long int x = a*b;

  if (a<b) {  //swap
    long int tmp = a;
    a = b;
    b = tmp;
  }

  //ユークリッドの互除法
  long int r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }

  ans = x/b;
  printf("%ld\n", ans);
  return 0;
}
