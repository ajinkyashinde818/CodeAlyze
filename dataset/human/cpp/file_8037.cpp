#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long a[n];
  for(int i=0; i<n; i++) cin >> a[i];
  long long prefix[n];
  prefix[0] = a[0];
  for(int i=1; i<n; i++) prefix[i] = a[i] + prefix[i-1];
  long long ans = 1e15;
  for(int i = 0; i<n-1; i++) ans = min(abs(prefix[i] - (prefix[n-1] - prefix[i])), ans);
  cout << ans << endl;
  return 0;
}
