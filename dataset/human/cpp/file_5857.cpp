#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int i;
  long long n, c;
  scanf("%lld %lld", &n, &c);
  long long x[100010], v[100010], right[100010], left[100010], right_max[100010], left_max[100010];
  x[0] = 0;
  v[0] = 0;
  for (i = 1; i < n+1; i++) {
    long long xi, vi;
    scanf("%lld %lld", &x[i], &v[i]);
  }
  x[n+1] = c;
  v[n+1] = 0;
  right[0] = 0;
  right_max[0] = 0;
  for (i = 1; i < n+1; i++) {
    right[i] = right[i-1] + v[i] - (x[i] - x[i-1]);
    right_max[i] = max(right_max[i-1], right[i]);
  }
  left[0] = 0;
  left_max[0] = 0;
  for (i = 1; i < n+1; i++) {
    left[i] = left[i-1] + v[n+1-i] - (x[n+2-i] - x[n+1-i]);
    left_max[i] = max(left_max[i-1], left[i]);
  }
  /*for (i = 0; i < n+1; i++) {
    printf("x=%lld v=%lld r=%lld l=%lld rmax=%lld lmax=%lld\n", x[i], v[i], right[i], left[i], right_max[i], left_max[i]);
    }*/
  long long ans = 0;
  for (i = 0; i < n+1; i++) {
    ans = max(ans, right[i]);
    ans = max(ans, right[i] + (left_max[n-i] - x[i]));
    ans = max(ans, left[i]);
    ans = max(ans, left[i] + (right_max[n-i] - (c - x[n+1-i])));
  }
  printf("%lld", ans);
  return 0;
}
