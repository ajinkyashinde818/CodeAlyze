#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> void SortUnique(vector<T> &vs) {
  sort(vs.begin(), vs.end());
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
}

struct Node {
  bool IsLeaf() const { return !m_left && !m_right; }

  Node *MoveLeft() {
    if (!m_left)
      m_left = new Node{};
    return m_left;
  }

  Node *MoveRight() {
    if (!m_right)
      m_right = new Node{};
    return m_right;
  }

  Node *m_left = nullptr;
  Node *m_right = nullptr;
};

void Add(Node *root, string const &s) {
  assert(root);

  for (auto const &c : s) {
    if (c == '0')
      root = root->MoveLeft();
    else
      root = root->MoveRight();
  }
}

uint64_t GetSG(uint64_t height) {
  height++;
  return height & ((~height) + 1);
}

void Dfs(Node *root, uint64_t depth, uint64_t maxLength,
         vector<uint64_t> &sgs) {
  if (!root)
    return;

  if (root->m_left)
    Dfs(root->m_left, depth + 1, maxLength, sgs);
  else if (depth < maxLength)
    sgs.push_back(GetSG(maxLength - depth - 1));

  if (root->m_right)
    Dfs(root->m_right, depth + 1, maxLength, sgs);
  else if (depth < maxLength)
    sgs.push_back(GetSG(maxLength - depth - 1));
}

int main() {
  ios_base::sync_with_stdio(0);

  // int const kMaxL = 100;

  // int g_table[kMaxL];
  // g_table[0] = 1;
  // for (int l = 1; l < kMaxL; ++l) {
  //   vector<int> mex;

  //   for (int p = 0; p <= l; ++p) {
  //     int x = 0;
  //     for (int i = 0; i < p; ++i)
  //       x = x ^ g_table[l - i - 1];
  //     mex.push_back(x);
  //   }
  //   SortUnique(mex);
  //   int i = 0;
  //   while (i < mex.size() && mex[i] == i)
  //     ++i;
  //   g_table[l] = i;
  // }

  // for (int i = 0; i < kMaxL; ++i)
  //   cout << i << ": " << g_table[i] << endl;

  int n;
  uint64_t maxLength;

  cin >> n >> maxLength;

  Node root;

  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    Add(&root, s);
  }

  vector<uint64_t> sgs;
  Dfs(&root, 0 /* depth */, maxLength, sgs);

  uint64_t x = 0;
  for (auto const & sg : sgs)
    x = x ^ sg;

  if (x == 0)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
  return 0;
}
