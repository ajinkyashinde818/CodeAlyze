#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int64_t a[n], sum=0, ct=0, ans=pow(10, 15);
  for(int i=0; i<n; i++){
    cin >> a[i];
    sum+=a[i];
  }
  ct=a[0];
  sum-=a[0];
  ans=abs(ct-sum);
  for(int i=1; i<n-1; i++){
    ct+=a[i];
    sum-=a[i];
    if(abs(ct-sum)<ans)
      ans = abs(ct-sum);
  }
  cout << ans;
  return 0;
}
