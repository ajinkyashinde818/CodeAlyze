#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
int V;
int A[100001], B[100001];
int K;
int U[100001], R[100001];
vector<int> G[100001];

int find(int x) {
  if (U[x] == x) return x;
  return U[x] = find(U[x]);
}

void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (R[x] < R[y]) swap(x, y);
  U[y] = x;
  R[x] += R[y];
  R[y] = 0;
  K--;
}

bool same(int x, int y) {
  return find(x) == find(y);
}

void add_edge(int x, int y) {
  G[x].pb(y);
  G[y].pb(x);
  unite(x, y);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  int g = 0;
  rep(i, N) {
    cin >> A[i];
    g ^= A[i];
  }
  A[N] = g;

  g = 0;
  rep(i, N) {
    cin >> B[i];
    g ^= B[i];
  }
  B[N] = g;

  vector<int> as, bs;
  rep(i, N+1) {
    as.pb(A[i]);
    bs.pb(B[i]);
  }
  sort(all(as));
  sort(all(bs));
  if (as != bs) {
    cout << -1 << "\n";
    return 0;
  }
  rep(i, N+1) assert(as[i] == bs[i]);
  uniq(as);
  V = as.size();
  rep(i, N+1) {
    A[i] = lower_bound(all(as), A[i]) - as.begin();
    B[i] = lower_bound(all(as), B[i]) - as.begin();
  }
  //rep(i, N+1) cout<<A[i]<<","; cout<<"\n";
  //rep(i, N+1) cout<<B[i]<<","; cout<<"\n";
  K = V;
  rep(i, V) U[i] = i, R[i] = 1;

  int edges = 0;
  rep(i, N) {
    if (A[i] == B[i]) continue;
    add_edge(A[i], B[i]);
    edges++;
  }
  rep(i, V) if (G[i].empty()) K--;

  int s = B[N], t = A[N];
  assert(same(s, t));
  if (G[s].empty()) K++;
  assert(K > 0);

  cout << edges+K-1 << "\n";
  return 0;
}
