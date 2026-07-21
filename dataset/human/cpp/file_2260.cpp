#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  vector<int> b(n);
  long long int ans = 0;
  int cnt = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    if(a[i] < 0)cnt++;
    b[i] = abs(a[i]);
    ans += b[i];
  }
  sort(b.begin(),b.end());
  if(cnt % 2 == 1)ans -= 2*b[0];
  cout << ans << endl;
}
