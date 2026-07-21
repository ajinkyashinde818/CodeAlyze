#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, L;
multiset<ll> X;

struct Node {
  ll x;
  Node *kids[2];
  Node(ll x) {
    this->x = x;
    kids[0] = kids[1] = nullptr;
  }
};
Node *Root;

ll R;

void go(const string &s, ll i, Node *node) {
  assert(node != nullptr);
  ll x = node->x;
  assert(x != 0);
  if (i == s.size()) {
    assert(x > 0);
    X.erase(X.find(x));
    node->x = 0;
    return;
  }
  if (x > 0) {
    assert(node->kids[0] == nullptr && node->kids[1] == nullptr);
    X.erase(X.find(x));
    node->x = -1;
    for (ll b : {0, 1}) {
      node->kids[b] = new Node(x - 1);
      X.insert(x - 1);
    }
  }
  go(s, i + 1, node->kids[s[i] - '0']);
}
int main() {
  cin >> N >> L;
  Root = new Node(L + 1);
  X.insert(L + 1);
  for (ll i = 0; i < N; ++i) {
    string s;
    cin >> s;
    go(s, 0, Root);
  }
  for (ll x : X) {
    R ^= x & (-x);
  }
  cout << (R != 0 ? "Alice" : "Bob") << endl;
}
