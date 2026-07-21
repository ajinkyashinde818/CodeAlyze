#include <stdio.h>

int main(){
  int n, d, x;  scanf("%d%d%d", &n, &d, &x);

  int ans = x + n;
  for(int i=0; i<n; i++){
    int t;  scanf("%d", &t);
    ans = ans + (d-1)/t;
  }

  printf("%d\n", ans);
  return 0;
}
