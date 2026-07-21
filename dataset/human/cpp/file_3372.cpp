#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  int minuscnt = 0;
  for(int i=0; i<n; ++i){
    cin >> an[i];
    if(an[i] < 0) ++minuscnt;
  }
  ll ans = 0;
  int m = INF;
  for(int i=0; i<n; ++i){
    ans += abs(an[i]);
    if(minuscnt%2){
      m = min(m, abs(an[i]));
    }
  }
  if(minuscnt%2) ans -= m*2;
  cout << ans << endl;
}
