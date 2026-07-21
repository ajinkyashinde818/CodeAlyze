#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main() {
  ll sum = 0;
  int N;
  cin >> N;
  vector<long long> vec(N);
  for (int i = 0;i < N;i++) {
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  ll ans = INF;
  ll temp = vec.at(0);
  ans = min(ans,abs(sum-temp*2));
  for (int i = 1;i<N-1;i++) {
    temp += vec.at(i);
    ans = min(ans,abs(sum - temp*2));
  }
  cout << ans << endl;
}
