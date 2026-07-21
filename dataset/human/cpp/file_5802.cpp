#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<const int CHAR_NUM = 26, const char FIRST_CHAR = 'a', const int NONE = -1>
struct Trie {
    struct Node {
        bool word_exists;
        int idxs[CHAR_NUM]; // idxs[c - FIRST_CHAR]: 次の文字がcであるNodeの場所(treeのindex)
        Node() : word_exists(false) {
            fill(idxs, idxs + CHAR_NUM, NONE);
        };
    };

    vector<Node> tree;

    Trie() {
        tree.emplace_back();
    }

    void insert(const string& s) {
        int cur = 0;
        for (char c : s) {
            if (tree[cur].idxs[c - FIRST_CHAR] == NONE) {
                tree[cur].idxs[c - FIRST_CHAR] = tree.size();
                tree.emplace_back();
            }
            cur = tree[cur].idxs[c - FIRST_CHAR];
        }
        tree[cur].word_exists = true;
    }

    bool find(const string& s) {
        int cur = 0;
        for (char c : s) {
            if (tree[cur].idxs[c - FIRST_CHAR] == NONE) {
                return false;
            }
            cur = tree[cur].idxs[c - FIRST_CHAR];
        }
        return tree[cur].word_exists;
    }

    void solve(int cur, int idx, vector<ll>& hoge, ll L) {
        if ((tree[idx].idxs[0] == NONE) ^ (tree[idx].idxs[1] == NONE)) hoge.push_back(L - cur);
        if (tree[idx].idxs[0] != NONE) solve(cur + 1, tree[idx].idxs[0], hoge, L);
        if (tree[idx].idxs[1] != NONE) solve(cur + 1, tree[idx].idxs[1], hoge, L);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll L;
    cin >> n >> L;

    Trie<2, '0'> tr;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        tr.insert(s);
    }

    vector<ll> hoge;
    tr.solve(0, 0, hoge, L);
    ll foo = 0;
    for (ll x : hoge) {
        int cnt = 0;
        while (x > 0) {
            if (x & 1) break;
            cnt++;
            x >>= 1;
        }
        foo ^= (1LL << cnt);
    }
    cout << (foo != 0 ? "Alice" : "Bob") << endl;
    return 0;
}
