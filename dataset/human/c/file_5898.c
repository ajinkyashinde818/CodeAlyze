#include <stdio.h>
int main(){
  int a = -1e9, b, i, n, r;
  scanf("%d%d", &n, &b);
  for(i = 1; i < n; i++){
    scanf("%d", &r);
    if(r-b > a) a = r-b;
    if(b > r) b = r;
  }
  printf("%d\n", a);
  return 0;
}
