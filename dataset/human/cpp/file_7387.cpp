#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  int n;
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];

  long long acc[n];
  acc[0] = a[0];
  for (int i=1; i<n; i++) {
    acc[i] = acc[i-1] + a[i];
  }
  long long ans = 2*1e14;
  for (int i=0; i<n-1; i++) {
    long long x = acc[i];
    long long y = acc[n-1] - acc[i];
    ans = min(ans, abs(x-y));
  }
  cout<<ans<<endl;
}
