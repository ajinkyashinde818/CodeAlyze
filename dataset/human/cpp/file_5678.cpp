#include <bits/stdc++.h>
using namespace std;

struct node {
    node* child[2];
    long long depth;
    bool end = false;
    node(long long d, bool isEnd) {
        child[0] = NULL; child[1] = NULL;
        depth = d;
        end = isEnd;
    }
};

int main() {
    int n; long long l; cin >> n >> l;
    node* root = new node(0, false);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        node* cur = root;
        for (int j = 0; j < s.size(); j++) {
            int t = s[j] - '0';
            if (cur->child[t] == NULL) {
                cur->child[t] = new node(cur->depth+1, false);
            }
            cur = cur->child[t];
        }
        cur->end = true;
    }
    long long ret = 0;
    queue<node*> q; q.push(root);
    while (!q.empty()) {
        node* cur = q.front(); q.pop();
        if (cur->depth == l) continue;
        if (cur->end) continue;
        for (int i = 0; i < 2; i++) {
            if (cur->child[i] == NULL) {
                long long c = l - cur->depth;
                ret ^= (c & -c); 
            } else q.push(cur->child[i]);
        }
    }
    if (ret != 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}
