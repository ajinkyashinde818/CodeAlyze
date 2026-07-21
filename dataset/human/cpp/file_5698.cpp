// forked from https://beta.atcoder.jp/contests/arc087/submissions/2069621
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
#include <memory>
using namespace std;

struct node_t {
        shared_ptr<node_t> left, right;
        node_t(shared_ptr<node_t> l, shared_ptr<node_t> r) : left(l), right(r) {}
};

using node = shared_ptr<node_t>;

node new_node() {
        return node(new node_t(NULL, NULL));
}

int main() {
        int n;
        long long l;
        scanf("%d %lld", &n, &l);
        vector<string> s(n);
        for (int i = 0; i < n; i ++) {
                cin >> s[i];
        }
        node root = new_node();
        function<void (node, const string&, int)> dfs = [&](node u, const string& str, int depth) {
                if (depth >= (int) str.size()) {
                        return;
                }
                if (str[depth] == '0') {
                        if (u->left == NULL) {
                                u->left = new_node();
                        }
                        dfs(u->left, str, depth + 1);
                } else {
                        if (u->right == NULL) {
                                u->right = new_node();
                        }
                        dfs(u->right, str, depth + 1);
                }
        };
        for (int i = 0; i < n; i ++) {
                dfs(root, s[i], 0);
        }
        function<long long (long long)> get_grundy = [&](long long x) {
                int ctz = __builtin_ctzll(x);
                return 1LL << ctz;
        };
        long long ans = 0;
        function<void (node, int)> dfs2 = [&](node u, int depth) {
                if ((u->left == NULL && u->right != NULL) || (u->left != NULL && u->right == NULL)) {
                        ans ^= get_grundy(l - depth);
                }
                if (u->left != NULL) {
                        dfs2(u->left, depth + 1);
                }
                if (u->right != NULL) {
                        dfs2(u->right, depth + 1);
                }
        };
        dfs2(root, 0);
        puts(ans ? "Alice" : "Bob");
        return 0;
}
