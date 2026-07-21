#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1LL << 60;
constexpr int INF = 3000000007;
const double INFD = 1e100;
const int mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  ll sum=0;
  ll cnt=0;
  for(int i=0; i<N; i++){
    ll a;
    cin >> a;
    if(a < 0){
      cnt++;
    }
    A[i] = abs(a);
    sum += A[i];
  }
  sort(A.begin(),A.end());
  if(cnt%2){
    sum -= A[0]*2;
  }
  cout << sum << endl;
  return 0;
}
