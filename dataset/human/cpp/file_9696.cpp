#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
typedef long long ll;
 
int main(){
  ll n;
  string s;
  cin >> n >> s;
  ll mod=1000000007;
  ll a[26];
  for(int i=0;i<26;i++){
    a[i]=0;
  }
  for(int i=0;i<n;i++){
    ll k=s.at(i)-'a';
    a[k]++;
  }
  ll ans=a[0];
  for(int i=1;i<26;i++){
    ans=(ans*(a[i]+1)+a[i])%mod;
  }
  cout << ans << endl;
}
