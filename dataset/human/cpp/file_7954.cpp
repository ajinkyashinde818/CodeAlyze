#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> to(N-1);
  long long a;
  cin >> a;
  to[0] = a*2;
  for (int i=1; i<N-1; i++) {
    cin >> a;
    a *= 2;
    to[i] = to[i-1] + a;
  }
  cin >> a;
  long long sum = (to[N-2] + a*2)/2;
  cerr << sum << endl;
  long long ans = 1010101010101010;
  for (int i=0; i<N-1; i++) {
    to[i] -= sum;
    to[i] = abs(to[i]);
    ans = min(ans,to[i]);
  }
  cout << ans << endl;
  
  return 0;
}
