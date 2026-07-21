#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

struct Trie {
    Trie *next[2];

    Trie() { next[0] = next[1] = NULL; }
};

void insert(const char *s, Trie *t) {
    for (int i = 0; s[i]; i++) {
        int c = s[i] - '0';
        if (!t->next[c]) t->next[c] = new Trie;
        t = t->next[c];
    }
}

vector<ll> g;
int N;
ll L;

void calc(Trie *t, int d) {
    int cnt = 0;
    if (t->next[0] != NULL) {
        calc(t->next[0], d + 1);
        cnt++;
    }
    if (t->next[1] != NULL) {
        calc(t->next[1], d + 1);
        cnt++;
    }
    if (cnt == 1 && L - d > 0) {
        ll sz = L - d;
        int k = 0;
        while (sz % 2 == 0) {
            sz /= 2;
            k++;
        }
        g.push_back(1LL << k);
    }
}

int main() {
    cin >> N >> L;
    Trie *t = new Trie;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        insert(s.c_str(), t);
    }
    calc(t, 0);
    ll ans = 0;
    for (int i = 0; i < g.size(); i++) {
        ans ^= g[i];
    }
    if (ans == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}
