#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

struct node {
    int depth;
    node *l, *r;
    node(int d) : depth(d), l(nullptr), r(nullptr) {}
};

node *add_char(node *v, char c) {
    if (c == '0') {
        if (v->l != nullptr) {
            return v->l;    
        } else {
            v->l = new node(v->depth + 1);
            return v->l;
        }
    } else {
        if (v->r != nullptr) {
            return v->r;
        } else {
            v->r = new node(v->depth + 1);
            return v->r;
        }
    }
}

node *add_string(node *v, string s) {
    for (char c: s) {
        v = add_char(v, c);
    }
    return v;
}

i64 grundy(i64 k) {
    for (int i = 0;; i++) {
        if ((k >> i) & 1) {
            return i64(1) << i;
        }
    }
}

int main() {
    i64 n, l;
    cin >> n >> l;
    node *root = new node(0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add_string(root, s);
    }

    vi ps;
    function<void(node*)> dfs = [&](node *v) {
        if (v->l && v->r) {
            dfs(v->l);
            dfs(v->r);
        } else if (v->l == nullptr && v->r == nullptr) {
            return;
        } else {
            if (v->l) {
                dfs(v->l);
                ps.push_back(l - v->depth);
            } else {
                dfs(v->r);
                ps.push_back(l - v->depth);
            }
        }
    };

    dfs(root);

    // for (i64 p: ps) {
    //     cout << p << endl;
    // }

    i64 x = 0;
    for (i64 p: ps) {
        x ^= grundy(p);
    }

    cout << (x ? "Alice" : "Bob") << endl;
}
