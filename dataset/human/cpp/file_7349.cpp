#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

  int n;
  int a[200000];
  long long sum = 0, x = 0;
  long long ans[200000];

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
    sum += a[i];
  }
  
  x += a[0]; sum -= a[0];
  long long min_t = abs(x - sum);
  for(int i = 1; i < n - 1; i++){
    x += a[i];
    sum -= a[i];
    ans[i] = abs(sum - x);
  }

  for(int i = 1; i < n - 1; i++){
    if(ans[i] < min_t)
    min_t = ans[i];
  }
  printf("%lld\n", min_t);

  return 0;
}
