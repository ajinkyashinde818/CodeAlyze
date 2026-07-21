#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
Int LSB(Int x) { return x & -x; }
struct Tree {
    Tree(Int h) {
        height = h;
        grundy = 0;
        p[0] = p[1] = nullptr;
    }
    void insert(const string &str, int idx) {
        if (idx >= str.size()) return;
        int t = str[idx] - '0';
        if (p[t] == nullptr) {
            p[t] = new Tree(height - 1);
        }
        p[t]->insert(str, idx + 1);
        grundy = 0;
        for (int i = 0; i < 2; i++) {
            grundy ^= (p[i] ? p[i]->grundy : LSB(height));
        }
    }
    Int height, grundy;
    Tree *p[2];
};
int main() {
    Int N, L; cin >> N >> L;
    Tree root(L);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        root.insert(s, 0);
    }
    cout << (root.grundy ? "Alice" : "Bob") << '\n';
    return 0;
}
