#include<stdio.h>

int main(){
  int n, a[20], b[20], c[20], i, ans = 0, k;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) scanf("%d", &a[i]);
  for(i = 0; i < n; ++i) scanf("%d", &b[i]);
  for(i = 0; i < n - 1; ++i) scanf("%d", &c[i]);
  k = a[0] - 1;
  ans = b[k];
  for(i = 1; i < n; ++i){
    if(a[i] == a[i - 1] + 1) ans += c[a[i] - 2];
    ans += b[a[i] - 1];
  }
  printf("%d\n", ans);
  return 0;
}
