#include <stdio.h>

int main(){
  int n,d,x;
  scanf("%d%d%d", &n, &d, &x);
  int a[n];
  int i;
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }
  int ans = x;
  for(i=0;i<n;i++){
    ans += (d-1)/a[i] + 1;
  }
  printf("%d\n", ans);
  return 0;
}
