#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  long long sum = 0;
  for ( int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  long long crr = 0, ans = ( 2 * 100000000000000);
  for ( int i = 0; i < n - 1; i++){
    crr += a[i];
    ans = min( ans, abs(sum - crr - crr) );
  }

  cout << ans << endl;

  return 0;
}
