#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long a[200001] = {};
  cin >> n;

  int tmp;
  for(int i = 1;i <= n;i++){
    cin >> tmp;
    a[i] = a[i-1]+tmp;
  }

  long long ans = LLONG_MAX;
  for(int i = 1;i < n;i++){
    ans = min(ans,llabs(a[i]-(a[n]-a[i])));
  }

  cout << ans << endl;
  return 0;
}
