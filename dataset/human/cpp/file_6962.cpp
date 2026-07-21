#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::vector<long long> A, std::vector<long long> B) {
  priority_queue<pair<ll, ll>> a;
  ll cur = A[0];
  ll count = 1;
  FOR(i, 1, N) {
    if (cur != A[i]) {
      a.emplace(count, cur);
      cur = A[i];
      count = 1;
    } else {
      count++;
    }
  }
  a.emplace(count, cur);
  priority_queue<pair<ll, ll>> b;
  cur = B[0];
  count = 1;
  FOR(i, 1, N) {
    if (cur != B[i]) {
      b.emplace(count, cur);
      cur = B[i];
      count = 1;
    } else {
      count++;
    }
  }
  b.emplace(count, cur);
  vector<pair<ll, ll>> ans;
  REP(i, N) {
    auto x = a.top();
    a.pop();
    auto y = b.top();
    b.pop();
    if (x.first == 1 && y.first == 1) {
      a.emplace(x);
      b.emplace(y);
      break;
    }
    if (x.second == y.second) {
      if (b.empty()) {
        cout << NO << endl;
        return;
      }
      auto z = b.top();
      b.pop();
      swap(y, z);
      b.push(z);
    }
    ans.emplace_back(x.second, y.second);
    if (x.first > 1) {
      a.emplace(x.first - 1, x.second);
    }
    if (y.first > 1) {
      b.emplace(y.first - 1, y.second);
    }
  }
  vector<ll> c;
  vector<ll> d;
  while (!a.empty()) {
    auto x = a.top();
    a.pop();
    c.push_back(x.second);
    auto y = b.top();
    b.pop();
    d.push_back(y.second);
  }
  sort(ALL(c));
  sort(ALL(d));
  REP(j, c.size()) {
    bool ok = true;
    REP(i, c.size()) {
      if (c[i] == d[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      REP(i, c.size()) {
        ans.emplace_back(c[i], d[i]);
      }
      sort(ALL(ans));
      cout << YES << endl;
      REP(i, N) {
        cout << ans[i].second << " ";
      }
      cout << endl;
      return;
    }
    rotate(c.begin(), c.begin() + 1, c.end());
  }
  cout << NO << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  std::vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &B[i]);
  }
  solve(N, std::move(A), std::move(B));
  return 0;
}
