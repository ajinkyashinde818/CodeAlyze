#include <stdio.h>
#define abs(a) ((a) > 0 ? (a) : -(a))

int
main(int argc, char *argv[])
{
  int n, m, a[100005], d[100005];
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) scanf("%d", &a[i]);

   long long x[100005]; x[0] = 1; x[1] = 2;
  for(int i = 2; i <= n; i++) {
    x[i] = x[i - 1] + x[i - 2];
    x[i] = x[i] % 1000000007;
  }

  d[0] = a[0] - 1;
  if(m != 0){
  for(int i = 1; i < m; i++){
    d[i] = a[i] - a[i - 1] - 2;
  }
  d[m] = n - a[m - 1] - 1;
 

  long long ans = 1;

  for(int i = 0; i <= m; i++){
    if(d[i] < 0){ans = 0; break;}
    else if(d[i] == 0) continue;
    else {
      ans = (ans * x[d[i] - 1]);
      ans = ans % 1000000007;
    }
  }
  printf("%lld\n", ans);
  }

  else{
    printf("%lld\n", x[n - 1]);
  }

 

  return 0;
}
