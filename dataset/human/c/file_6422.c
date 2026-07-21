#include <stdio.h>
#include <limits.h>
#define MAX_N 200000
typedef long long ll;
ll max(ll a, ll b) {
  if(a < b) return b;
  return a;
}
int main() {
  ll n, R[MAX_N], mn = LLONG_MAX/2, ans = -LLONG_MAX;  
  int i;
  scanf("%lld", &n);
  for(i = 0; i < n; i++) scanf("%lld", R+i);
  for(i = 0; i < n; i++) {
    ans = max(ans, R[i] - mn);    
    if(R[i] < mn) mn = R[i];
  }
  printf("%d\n", ans);
  return 0;
}
