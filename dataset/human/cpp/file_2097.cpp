//not answered
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#include <algorithm>

int main() {
  int n;
  cin >> n;
  
  vector<lli> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  vector<lli> dp0(n+1);
  vector<lli> dp1(n+1);
  
  dp0[0] = a[0];
  dp1[0] = - a[0];
  for(int i = 1; i < n; i++){
    dp0[i] = max(dp0[i-1] + a[i], dp1[i-1] - a[i]);
    dp1[i] = max(dp0[i-1] - a[i], dp1[i-1] + a[i]);
  }
  
  cout << dp0[n-1] << endl;
  
}
