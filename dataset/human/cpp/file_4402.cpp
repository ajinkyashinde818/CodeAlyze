#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

// Does coordinate compression.
// Arguments:
// - raw_xs: Values to compress.
// Returns:
// - xs: Compressed values.
// - to_raw: A mapping from a compressed value to a raw value.
// Verified: CF573Div1D
tuple<vector<int>, vector<int>> Compress(const vector<int>& raw_xs) {
  unordered_set<int> raw_x_set(raw_xs.begin(), raw_xs.end());
  vector<int> to_raw(raw_x_set.begin(), raw_x_set.end());
  sort(to_raw.begin(), to_raw.end());
  unordered_map<int, int> to_index;
  for (int i = 0; i < to_raw.size(); i++) {
    to_index[to_raw[i]] = i;
  }
  vector<int> xs;
  for (int raw_x : raw_xs) {
    xs.push_back(to_index[raw_x]);
  }
  return make_tuple(xs, to_raw);
}

class UFSet {
 private:
  vector<int> ranks;
  vector<int> prevs;

 public:
  UFSet(int n) : ranks(n), prevs(n) {
    for (int i = 0; i < n; i++) prevs[i] = i;
  }

  // Returns a root of a tree which x belongs to.
  int Find(int x) {
    if (x != prevs[x]) prevs[x] = Find(prevs[x]);
    return prevs[x];
  }

  // Merges a set which x blongs to and a set which y belongs to.
  void Union(int x, int y) {
    int x_root = Find(x);
    int y_root = Find(y);
    if (ranks[x_root] > ranks[y_root]) {
      prevs[y_root] = prevs[x_root];
    } else if (ranks[x_root] < ranks[y_root]) {
      prevs[x_root] = prevs[y_root];
    } else if (prevs[x_root] != prevs[y_root]) {
      prevs[y_root] = prevs[x_root];
      ranks[x_root]++;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> xs(n);
  vector<int> ys(n);
  for (int i = 0; i < n; i++) cin >> xs[i];
  for (int i = 0; i < n; i++) cin >> ys[i];
  int x_xor = 0;
  int y_xor = 0;
  for (int i = 0; i < n; i++) x_xor ^= xs[i];
  for (int i = 0; i < n; i++) y_xor ^= ys[i];

  vector<int> e_xs;
  e_xs.insert(e_xs.end(), xs.begin(), xs.end());
  e_xs.push_back(x_xor);
  vector<int> e_ys;
  e_ys.insert(e_ys.end(), ys.begin(), ys.end());
  e_ys.push_back(y_xor);
  sort(e_xs.begin(), e_xs.end());
  sort(e_ys.begin(), e_ys.end());
  for (int i = 0; i <= n; i++) {
    if (e_xs[i] != e_ys[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  vector<int> raw_zs;
  for (int i = 0; i < n; i++) {
    if (xs[i] != ys[i]) {
      raw_zs.push_back(xs[i]);
      raw_zs.push_back(ys[i]);
    }
  }
  if (x_xor != y_xor) {
    raw_zs.push_back(x_xor);
    raw_zs.push_back(y_xor);
  }
  vector<int> zs;
  vector<int> to_raw_z;
  tie(zs, to_raw_z) = Compress(raw_zs);

  int m = to_raw_z.size();
  UFSet uf_set(m);
  for (int i = 0; i < zs.size() / 2; i++) {
    int z1 = zs[2 * i];
    int z2 = zs[2 * i + 1];
    uf_set.Union(z1, z2);
  }

  set<int> component_set;
  for (int i = 0; i < m; i++) {
    component_set.insert(uf_set.Find(i));
  }

  int ans = zs.size() / 2;
  ans += component_set.size();
  if (x_xor != y_xor) {
    ans -= 2;
  } else {
    bool valid = false;
    for (int raw_z : raw_zs) {
      if (raw_z == x_xor) {
        valid = true;
      }
    }
    if (valid) ans--;
  }
  cout << ans << endl;
}
