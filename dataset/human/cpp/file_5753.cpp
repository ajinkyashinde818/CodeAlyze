#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    lint n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    struct node {
        int d, lch, rch;
    };
    vector<node> nodes;
    nodes.push_back({0, -1, -1});
    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < (int)s[i].size(); ++j) {
            if (s[i][j] == '0') {
                if (nodes[c].lch == -1) {
                    nodes[c].lch = nodes.size();
                    nodes.push_back({nodes[c].d + 1, -1, -1});
                    c = nodes[c].lch;
                } else {
                    c = nodes[c].lch;
                }
            } else {
                if (nodes[c].rch == -1) {
                    nodes[c].rch = nodes.size();
                    nodes.push_back({nodes[c].d + 1, -1, -1});
                    c = nodes[c].rch;
                } else {
                    c = nodes[c].rch;
                }
            }
        }
    }
    lint gr = 0;
    for (auto &v : nodes) {
        if (v.lch == -1 && v.rch == -1) {
            continue;
        } else if (v.lch == -1 || v.rch == -1) {
            lint t = (v.d - l) & (l - v.d);
            gr     = gr ^ t;
        }
    }
    if (gr == 0) {
        cout << "Bob"
             << "\n";
    } else {
        cout << "Alice"
             << "\n";
    }
    return 0;
}
