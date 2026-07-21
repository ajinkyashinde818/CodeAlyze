#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
const int mod = 1e9+7;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vi c(26);
  for (char x : s) c[x-'a']++;
  ll res = 1;
  for (int x : c) res = res * (x + 1) % mod;
  cout << (res + mod - 1) % mod << endl;
  return 0;
}
