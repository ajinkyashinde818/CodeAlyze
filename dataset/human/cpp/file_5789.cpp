#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    node() : next(2) {}
    vector<unique_ptr<node>> next;
};

void insert(node* p, int i, string const& s) {
    if(i == (int)s.size()) return;
    const int idx = s[i] - '0';
    if(!p->next[idx]) p->next[idx] = make_unique<node>();
    insert(p->next[idx].get(), i + 1, s);
}

int main() {
    ll n, l; cin >> n >> l;
    auto root = make_unique<node>();
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        insert(root.get(), 0, s);
    }

    function<ll(node*, int)> dfs = [&] (node* p, int depth) {
        if(!p->next[0] && !p->next[1]) return 0LL;
        if(p->next[0] && p->next[1]) {
            return dfs(p->next[0].get(), depth + 1) ^ dfs(p->next[1].get(), depth + 1);
        }
        if(p->next[1]) swap(p->next[0], p->next[1]);
        ll cnt = 0, dist = l - depth;
        while(dist % 2 == 0) {
            cnt += 1;
            dist >>= 1;
        }
        return dfs(p->next[0].get(), depth + 1) ^ (1LL << cnt);
    };

    cout << (dfs(root.get(), 0) ? "Alice" : "Bob") << endl;
}
