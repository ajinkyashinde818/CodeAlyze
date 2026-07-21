#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


long long a[200001];

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long d; cin >> d;
    a[i] += d;
    a[i+1] = a[i];
  }
  long long m = a[n-1];
  long long ans = 1e18;
  for (int i = 0; i < n-1; i++) {
    long long t = m - 2 * a[i];
    ans = min(ans, max(t, -t));
  }
  cout << ans << endl;
  return 0;
}
