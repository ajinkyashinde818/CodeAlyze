#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<sstream>
#include<string>
#include<utility>
#include<vector>

#define rep(i, a, n)  for(int i=a; i<n; ++i)
#define per(i, a, n)  for(int i=n-1; i>=a; --i)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 1000000007;
using namespace std;
typedef long long ll;

int main(){
  int N;  cin >> N;
  vector<ll> a(N);
  int n = 0;
  ll Sum = 0;
  ll m = pow(10, 18);
  rep(i, 0, N){
    cin >> a[i];
    Sum += abs(a[i]);
    n += (a[i]<0 ? 1 : 0);
  }

  rep(i, 0, N){
    m = min(m, abs(a[i]));
  }
  if(n&1) cout << Sum - 2*m << endl;
  else  cout << Sum << endl;
  return 0;
}
