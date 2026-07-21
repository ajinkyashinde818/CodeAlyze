#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Node {
    Node* go[2];
    Node() {
        go[0] = go[1] = nullptr;
    }
};

Node* root = new Node();
int ans = 0;

int gr(ll x) {
    int ans = 1;
    while (x % 2 == 0) {
        ans++;
        x /= 2;
    }
    return ans;
}

void dfs(Node* v, ll h) {
    if (v == nullptr) {
        return;
    }
    int sm = 0;
    for (int i = 0; i < 2; i++) {
        dfs(v->go[i], h - 1);
        if (!v->go[i]) {
            sm++;
        }
    }
    if (sm == 1) {
        ans ^= gr(h);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    ll l;
    cin >> l;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        Node* v = root;
        for (int j = 0; j < s.size(); j++) {
            int x = s[j] - '0';
            if (v->go[x] == nullptr) {
                v->go[x] = new Node();
            }
            v = v->go[x];
        }
    }
    dfs(root, l);
    cout << (ans ? "Alice" : "Bob") << "\n";
}
