#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> book(n), mid_sum(n);
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin >> book.at(i);
    sum += book.at(i);
    mid_sum.at(i) = sum;
  }
  ll ans = 10000000000;
  for(int i = 0; i < n-1; i++){
    ans = min(ans,abs(mid_sum.at(i)-(sum-mid_sum.at(i))));
  }
  cout << ans << endl;
  
}
