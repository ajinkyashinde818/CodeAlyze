#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n; cin >> n;
  vector<long long> a(n);
  vector<long long> s(n); // 累積和
  for(int i=0;i<n;i++) cin >> a[i];
  s[0] = a[0];
  for(int i=1;i<n;i++){
    s[i] = s[i-1] + a[i];
  }
  long long ans = abs(s[0]*2 - s[n-1]);
  // 両者とも1枚はとらなければならない
  for(int i=0;i<n-1;i++){
    ans = min(ans,abs(s[i]*2 - s[n-1]));
  }
  
  cout << ans << endl;
  return 0;
}
