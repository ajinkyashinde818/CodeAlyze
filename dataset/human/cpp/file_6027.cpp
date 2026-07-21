#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  long long n, c;
  cin >> n >> c;
  vector<long long> x(n+2), v(n+1);
  x[0] = 0; v[0] = 0; x[n+1] = c;
  for (int i = 1; i <= n; i++) {
    scanf("%lld  %lld", &x[i], &v[i]);
  }
  vector<long long> a(n+1), b(n+1);
  a[0] = 0; b[0] = 0;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i-1] + v[i] - (x[i] - x[i-1]);
    if (i == 1) b[i] += b[i-1] + v[n+1-i] - (c - x[n+1-i]);
    else b[i] += b[i-1] + v[n+1-i] - (x[n+2-i] - x[n+1-i]);
    //printf("%lld, %lld\n", a[i], b[i]);
  }
  //printf("\n");
  for (int i = 1; i <= n; i++) {
    a[i] = max(a[i-1], a[i]);
    b[i] = max(b[i-1], b[i]);
    //printf("%lld, %lld\n", a[i], b[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] + b[n-i] - x[i]);
    ans = max(ans, b[i] + a[n-i] - (c - x[n+1-i]));
  }
  cout << ans << endl;
  return 0;
}
