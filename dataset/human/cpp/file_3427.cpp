#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  int N; cin >> N;
  vector<ll> A(N),B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
 
  int count = 0;
  for (int i = 0; i < N; i++) if (A[i] < 0) count++;
  
  for (int i = 0; i < N; i++) B[i] = abs(A[i]);
  
  sort(B.begin(),B.end());
  
  ll ans = 0;
  for (int i = 0; i < N; i++) ans += B[i];
  if (B[0] != 0 && count % 2 == 1) ans -= 2*B[0];
  
  cout << ans << endl;
}
