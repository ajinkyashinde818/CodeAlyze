#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll MAX_N = 100010;
//const ll MAX_M = 100010;
//const ll MOD_P = 1000000000 + 7;
const ll INF = 1000000000000;
ll A[MAX_N];

int main() {

  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll N; 
  cin >> N;

  ll neg_cnt = 0;
  ll min_abs = INF;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if(A[i] < 0) neg_cnt++;
    min_abs = min(min_abs, abs(A[i]));
  }

  ll ans = 0;
  for (int i = 0; i < N; i++) ans += abs(A[i]);
  if(neg_cnt % 2 != 0) ans -= 2*min_abs;

  cout << ans << endl;

  return 0;
}
