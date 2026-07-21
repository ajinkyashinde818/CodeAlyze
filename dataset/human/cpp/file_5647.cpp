#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  lint l; cin >> l;
  V<string> s(n); for (int i = 0; i < n; i++) cin >> s[i];

  struct node { V<node*> chi; node() { chi.resize(2); } };
  node* tree = new node;
  auto add_str = [&](string s) {
    node* p = tree;
    for (char c : s) {
      if (p->chi[c -= '0'] == nullptr) p->chi[c] = new node;
      p = p->chi[c];
    }
  };
  for (int i = 0; i < n; i++) add_str(s[i]);

  lint grundy = 0;
  queue< pair<node*, lint> > q;
  q.emplace(tree, l);
  while (!q.empty()) {
    node* p; lint h; tie(p, h) = q.front(); q.pop();
    if ((p->chi[0] != nullptr) ^ (p->chi[1] != nullptr)) grundy ^= h & -h;
    for (int i = 0; i < 2; i++) if (p->chi[i] != nullptr) q.emplace(p->chi[i], h - 1);
  }
  cout << (grundy ? "Alice" : "Bob") << '\n';
}
