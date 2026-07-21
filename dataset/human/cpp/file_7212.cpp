#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long>sum(n);
  long long ans;
  cin >> sum[0];
  for(int i = 1;i < n;i++){
    long long a;
    cin >> a;
    sum[i] = a+sum[i-1];
  }
  ans = abs(sum[n-1]-2*sum[0]);
  for(int i = 1;i < n-1;i++){
    if(ans > abs(sum[n-1]-2*sum[i])) ans = abs(sum[n-1]-2*sum[i]);
  }
  cout << ans << endl;
}
