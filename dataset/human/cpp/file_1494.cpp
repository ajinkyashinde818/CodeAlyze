#include <stdio.h>
#include <vector>
#include <math.h>
typedef long long ll;
using namespace std;

int main(void) {
  ll i, j, k, n, now = 0, cnt = 1;
  scanf("%lld", &n);
  double ans = 1.0 + (double)n * 8.0;
  if(sqrt(ans) != (int)sqrt(ans)) {
    printf("No");
    return 0;
  }
  now = (int)((1.0 + sqrt(ans)) / 2.0);
  printf("Yes\n%lld\n", now);
  vector<ll> vec[now];
  for(i = 0; i < now; ++i) {
    for(j = i + 1; j < now; ++j) vec[i].push_back(cnt), vec[j].push_back(cnt), cnt++;
  }
  for(i = 0; i < now; ++i) {
    printf("%lld", 2 * n / now);
    for(j = 0; j < 2 * n / now; ++j) printf(" %lld", vec[i][j]);
    printf("\n");
  }
  return 0;
}
