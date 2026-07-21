#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<ll> a(N);
  for(int i = 0;i < N;i++)cin >> a[i];

  vector<ll> sums(N);
  sums[0] = a[0];
  for(int i = 1;i < N;i++)sums[i] = sums[i-1] + a[i];

  ll sum_all = sums[N-1];

  ll ans = 1e15;

  for(int i = 0;i < N - 1;i++){
    ll left = sum_all - sums[i];
    ll abs_ = max(left - sums[i],sums[i] - left);
    ans = min(abs_,ans);
  }

  cout << ans << endl;
}
