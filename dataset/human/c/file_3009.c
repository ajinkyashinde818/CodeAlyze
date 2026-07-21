#include <stdio.h>

int main(void){
  int k, n, a[200000]={0};
  int b[200000]={0}, i;
  int b_max=0, ans=0;
  scanf("%d %d", &k ,&n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  for(i=0; i<n-1; i++){
    b[i] = a[i+1] - a[i];
  }
  b[n-1] = k - a[n-1] + a[0];
  for(i=0; i<n; i++){
    if(b_max < b[i]){
      b_max = b[i];
    }
    ans += b[i];
  }
  ans -= b_max;
  printf("%d\n", ans);
  return 0;
}
