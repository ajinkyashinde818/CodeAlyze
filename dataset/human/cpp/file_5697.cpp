#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Trie {
    static constexpr int M = 1, O = '0';
    struct Node {
        int children[2];
        int count;
    };
    Trie() : nodes(1) {}
    void insert(const string& s) {
        int k = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - O;
            for (int j = M - 1; j >= 0; j--) {
                int v = c >> j & 1;
                int& p = nodes[k].children[v];
                if (p == 0) {
                    k = p = nodes.size();
                    nodes.push_back(Node());
                } else {
                    k = p;
                }
            }
        }
        nodes[k].count++;
    }
    void dfs(int k, int j, string& s) {
        int64_t d = s.size();

        if (j == 0) s.push_back(0); else s.back() <<= 1;
        if (++j == M) s.back() += O, j = 0;

        int c = 0;
        for (int v = 0; v < 2; v++) {
            int k1 = nodes[k].children[v];
            if (k1 == 0) continue;

            c++;
            if (v) s.back()++;
            int b = s.back(), n = s.size();
            dfs(k1, j, s);
            s.resize(n); s.back() = b;
        }

        if (c == 1) {
            //cout << s.size() << ' ' << s << endl;
            d = l - d;
            g ^= d & -d;
        }
    }
    vector<Node> nodes;
    int64_t g, l;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int64_t l;
    cin >> l;

    Trie tr;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        tr.insert(s);
    }
    tr.g = 0;
    tr.l = l;
    s.clear();
    tr.dfs(0, 0, s);

    cout << (tr.g != 0 ? "Alice" : "Bob") << endl;

    return 0;
}
