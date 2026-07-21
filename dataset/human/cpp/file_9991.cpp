#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  int MOD = 1000000007;
  int n; cin >>n;
  string s; cin >> s;
  vector <ll> num(26);
  rep(i, 26) num[i] = 0;
  for (char c:s){
    num[c-'a'] += 1;
  }
  ll ans = 1;
  rep(i, 26){
    if (num[i] != 0){
      ans *= (num[i]+1);
      ans %= MOD;
    }
  }
  cout << ans-1 << endl;
}
