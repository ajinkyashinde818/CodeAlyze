#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 1000000007;
const lli e3 = 1 << 13;
const lli INF = 1ll << 62;

lli n;
string s;
lli b[e5];
lli ans = 1;

int main(){
  cin >> n;
  cin >> s;
  for(lli i = 0;i < n;i++){
    b[s[i]]++;
  }
  for(lli i = 'a';i <= 'z';i++){
    ans *= (b[i]+1);
    ans %= mod;
  }
  cout << (ans-1+mod)%mod << endl;
}
