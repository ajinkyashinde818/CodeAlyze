#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  vector<lint> a(N);
  lint sum = 0, num = 0, p = 1e9;
  for(lint i = 0; i < N; i++){
    cin >> a[i];
    if(a[i] < 0) num++;
    sum += abs(a[i]);
    p = min(abs(a[i]), p);
  }
  if(count(a.begin(), a.end(), 0) != 0) cout << sum << endl;
  else{
    if(num % 2 == 0) cout << sum << endl;
    else cout << sum - 2*p << endl;
  }
}
