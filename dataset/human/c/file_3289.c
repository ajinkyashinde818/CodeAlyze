#include <stdio.h>

int main()
{
  int k, n, ans = 0;
  int tmp = 0;
  int a[1000000];
  int i;
  scanf("%d%d", &k, &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  tmp = a[0] + k - a[n - 1];
  for(i = 0; i < n - 1; i++){
    if(a[i + 1] - a[i] > tmp){
      ans += tmp;
      tmp = a[i + 1] - a[i];
    }else{
      ans += a[i + 1] - a[i];
    }
  }
  if(a[n - 1] - a[n - 2] > tmp){
    ans = k - (a[n - 1] - a[n - 2]);
  }
  printf("%d\n", ans);
  
  return 0;
}
