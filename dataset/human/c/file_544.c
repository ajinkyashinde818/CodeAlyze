#include <stdio.h>
#define abs(x) ((x)<0 ? -(x) : (x))
#define min(x, y) ((x)>(y) ? (y) : (x))

int main(){
  int n;  scanf("%d", &n);
  long a[200005] = {0};
  for(int i=1; i<=n; i++){
    long t;  scanf("%ld", &t);
    a[i] = a[i-1] + t;
  }

  long ans = ((long)1)<<62;
  for(int i=2; i<=n; i++){
    long sa = abs(a[n]-a[i-1]-a[i-1]);
    ans = min(ans, sa);
  }

  printf("%ld\n", ans);

  return 0;
}
