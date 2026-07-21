#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N,0);
  ll sum = 0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    sum += A[i];
  }
  sum -= 2*A[0];
  ll ans = abs(sum);
  for(int i=1;i<N-1;i++){
    sum -= 2*A[i];
    ans = min(ans,abs(sum));
  }
  cout << ans << endl;
}
