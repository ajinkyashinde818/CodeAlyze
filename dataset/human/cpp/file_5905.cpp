#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

template <class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(bool a) {
  return a ? "T" : "F";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;

const int N = 1e5 + 10;

ll n, c;
ll x[N];
ll v[N];
ll d[N];

ll getsum(int l, int r) {
  if (l > r) return 0;
  return d[r] - (l > 0 ? d[l - 1] : 0);
}

void run() {
  cin >> n;
  cin >> c;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> v[i];
  }

  partial_sum(v, v + n + 1, d);

  ll ans = 0;
  vector <ll> ans0(1, 0);
  for (int i = 1; i <= n; ++i) {
    ll tmp = getsum(1, i) - x[i];
    ans0.push_back(max(ans0.back(), tmp));
  }

  vector <ll> ans1(1, 0);
  for (int i = 1; i <= n; ++i) {
    ll tmp = getsum(i, n) - (c - x[i]);
    ans1.push_back(tmp);
  }
  ans1.push_back(0);
  for (int i = n; i >= 1; --i) {
    maxi(ans1[i], ans1[i + 1]);
  }

  vector <ll> mx0(1, 0);
  for (int i = 1; i <= n; ++i) {
    ll tmp = getsum(1, i) - x[i] * 2;
    mx0.push_back(tmp);
  }

  for (int i = 0; i <= n; ++i) {
    maxi(ans, mx0[i] + ans1[i + 1]);
  }
  
  vector <ll> mx1(1, 0);
  for (int i = 1; i <= n; ++i) {
    ll tmp = getsum(i, n) - (c - x[i]) * 2;
    mx1.push_back(tmp);
  }
  mx1.push_back(0);

  for (int i = 1; i <= n + 1; ++i) {
    maxi(ans, mx1[i] + ans0[i - 1]);
  }

  cout << ans << endl;
}

int main() {
  run();
  return 0;
}
