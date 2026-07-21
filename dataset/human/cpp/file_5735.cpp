#include <bits/stdc++.h>
using namespace std;

long long n, l;
const int dsize = 2;
long long calc(long long x) {
  if(x == 0) return 0;
  if(x % 2 == 1) return 1;
  long long now = 63;
  while(now--) {
    if(x % (1 << now) == 0) return now;
  }
  return 0;
}
struct Trie {
  struct data {
    int num;
    data *child[dsize];
    data(int nnum = -1) {
      num = nnum;
      fill(child, child + dsize, (data *)0);
    }
  };
  data root;
  Trie() { root = data(0); }
  void make(string x) {
    data *now = &root;
    for(int i = 0; i < x.size(); ++i) {
      if(!now->child[x[i] - '0'])
        now->child[x[i] - '0'] = new data(now->num + 1);
      now = now->child[x[i] - '0'];
    }
  }
  bool solve() {
    long long ans = 0;
    if(root.child[0]) ans ^= recall(root.child[0]);
    if(root.child[1]) ans ^= recall(root.child[1]);
    if((!root.child[0]) || (!root.child[1])) ans ^= calc(l);
    return ans == 0;
  }
  long long recall(data *now) {
    long long ans = 0;
    if((!now->child[0]) && (!now->child[1])) return 0;
    if((!now->child[0]) || (!now->child[1]))
      ans = calc(l - now->num);
    if(now->child[0]) ans ^= recall(now->child[0]);
    if(now->child[1]) ans ^= recall(now->child[1]);
    return ans;
  }
};
void prians(bool answer) {
  if(answer)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
}
Trie trie;
int main() {
  cin >> n >> l;
  for(int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    trie.make(s);
  }
  prians(trie.solve());
  return 0;
}
