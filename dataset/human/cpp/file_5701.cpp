#include <functional>
#include <vector>
#include <iostream>
using namespace std;

class Trie {
    struct Node {
        bool exists = false;
        int l = -1, r = -1;
    };
    vector<Node> nodes;
public:
    Trie () { nodes.push_back(Node()); }
    void add(string &s) {
        int i = 0;
        for (char c : s) {
            if (c == '0') {
                if (nodes[i].l >= 0) i = nodes[i].l;
                else {
                    const int i1 = nodes.size();
                    nodes[i].l = i1;
                    i = i1;
                    nodes.push_back(Node());
                }
            } else {
                if (nodes[i].r >= 0) i = nodes[i].r;
                else {
                    const int i1 = nodes.size();
                    nodes[i].r = i1;
                    i = i1;
                    nodes.push_back(Node());
                }
            }
        }
        nodes[i].exists = true;
    }
    long long solve(long long L) {
        long long ret = 0;
        function <void(int, long long)> dfs = [&](int i, long long h) {
            if (nodes[i].exists) return;
            if (nodes[i].l == -1) ret ^= h&-h;
            else dfs(nodes[i].l, h-1);
            if (nodes[i].r == -1) ret ^= h&-h;
            else dfs(nodes[i].r, h-1);
        };
        dfs(0, L);
        return ret;
    }
    void dump() {
        for (int i = 0; i < nodes.size(); i++) {
            Node nd = nodes[i];
            cerr << i << " " << (nd.exists ? "T" : "F") << " " << nd.l << " " << nd.r << endl;
        }
    }
};

int main() {
    int n;
    long long l; cin >> n >> l;
    Trie t;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        t.add(s);
    }
    long long g = t.solve(l);
    cout << (g == 0 ? "Bob\n" : "Alice\n");
}
