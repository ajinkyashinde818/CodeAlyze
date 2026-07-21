#include <cstdio>
#include <algorithm>

using namespace std;

int a[200500];

int main() {
  while(1) {
    int n;
    if( scanf("%d", &n) != 1) break;

    long long ans = (long long)1e18;

    long long sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }

    long long pref = 0;
    for(int i = 0; i+1 < n; i++) {
      pref += a[i];
      long long dif = pref - (sum - pref);
      if(dif < 0) dif = -dif;
      ans = min(ans, dif);
    }

    printf("%lld\n", ans);
  }
}
