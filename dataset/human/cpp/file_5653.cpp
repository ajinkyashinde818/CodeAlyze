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
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

inline long long f(long long x) {
  long long s = 1;
  while (1) {
    if (s&x) return s;
    s <<= 1;
  }
}

long long grundy;
int N;
long long L;

class Trie {
public:
  Trie *a[2];
  int rank;
  bool dead, after;

  Trie(int rank) : rank(rank) {
    a[0] = a[1] = NULL;
    dead = false;
    after = false;
  }
  void insert(const char *s) {
    assert(rank <= L);
    dead = true;
    if (*s == '\0') {
      after = true;
      return;
    }
    int k = *s - '0';
    if (a[k] == NULL) a[k] = new Trie(rank+1);
    a[k]->insert(s+1);
  }

  void solve() {
    if (after) return;
    if (!dead) {
      assert(false);
      return;
    }
    if (rank == L) return;
    rep(k, 2) {
      if (a[k] == NULL) {
        grundy ^= f(L-rank);
      }
      else a[k]->solve();
    }
  }
};

Trie trie(0);

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> L;
  trie.dead = true;
  rep(i, N) {
    string s;
    cin >> s;
    trie.insert(s.c_str());
  }
  grundy = 0;
  trie.solve();
  if (grundy == 0) cout << "Bob\n";
  else cout << "Alice\n";
  return 0;
}
