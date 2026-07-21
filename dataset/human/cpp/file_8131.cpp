#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return abs(a*b)/gcd(a,b);}
std::vector<bool> IsPrime; void sieve(size_t max){if(max+1 > IsPrime.size())IsPrime.resize(max+1,true);IsPrime[0] = false;IsPrime[1] = false;for(size_t i=2; i*i<=max; ++i)if(IsPrime[i])for(size_t j=2; i*j<=max; ++j)IsPrime[i*j] = false;}
#define roundup(divisor,dividend) (divisor + (dividend - 1)) / dividend
#define all(x) (x).begin(),(x).end()
#define size_t ll
ll n,ans=INT_MAX,s=0,t=0;
std::vector<int> a;
int main(){
  cin >> n;
  a.resize(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  for (size_t i = 0; i < n-1; i++) {
    t += a[i]; s -= a[i];
    if(ans > abs(t-s))ans=abs(t-s);
  }
  cout << ans << endl;
}
