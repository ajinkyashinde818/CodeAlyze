#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  int a[n], b[n], c[n];
  int i;
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }
  for(i=0;i<n;i++){
    scanf("%d", &b[i]);
  }
  for(i=0;i<n-1;i++){
    scanf("%d", &c[i]);
  }
  int ans = 0;
  int pre = n;
  for(i=0;i<n;i++){
    ans += b[a[i] - 1];
    if (a[i] == pre + 1) {
      ans += c[pre - 1];
    }
    pre = a[i];
  }
  printf("%d\n", ans);
  return 0;
}
