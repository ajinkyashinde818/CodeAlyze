#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	int len = v.size();
  s << "[";
	for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
		s << v[i];
	}
  s << "]";
	return s;
}

struct Node {
  Node* c0 = nullptr;
  Node* c1 = nullptr;
  void Add(const string& s, int cur) {
    if (cur >= s.length()) return;

    if (s[cur] == '0') {
      if (c0 == nullptr) {
        c0 = new Node();
      }
      c0->Add(s, cur + 1);
    } else if (s[cur] == '1') {
      if (c1 == nullptr) {
        c1 = new Node();
      }
      c1->Add(s, cur + 1);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int64 l;
  cin >> n >> l;

  Node trie;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    trie.Add(s, 0);
  }

  vector<int64> ds;
  function<void(Node*, int)> dfs_fn = [&](Node* node, int d) {
    if (node->c0 == nullptr && node->c1 == nullptr) {
      // Leaf.
    } else if (node->c0 == nullptr) {
      ds.push_back(l - d);
      dfs_fn(node->c1, d + 1);
    } else if (node->c1 == nullptr) {
      ds.push_back(l - d);
      dfs_fn(node->c0, d + 1);
    } else {
      dfs_fn(node->c0, d + 1);
      dfs_fn(node->c1, d + 1);
    }
  };
  dfs_fn(&trie, 0);

  if (DEBUG) cout << "ds: " << ds << endl;

  auto g_fn = [](int64 x) -> int64 {
    int64 v = 1;
    while (x % 2 == 0) {
      x /= 2;
      v *= 2;
    }
    return v;
  };

  int64 xor_value = 0;
  for (int64 d: ds) {
    xor_value ^= g_fn(d);
  }
  if (xor_value == 0) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
}
