#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  vector<long long> a(n);
  int neg = 0;
  ll tot = 0;
  for (int i=0; i<n; i++) {
    cin>>a[i];
    if (a[i]<0) { neg++; a[i]=-a[i]; }
    tot += a[i];
  }
  if (neg%2==0) {
    cout<<tot<<endl;
  } else {
    sort(a.begin(), a.end());
    tot -= 2LL*a[0];
    cout<<tot<<endl;
  }
  return 0;
}
