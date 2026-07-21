#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

const int MAXN = (int) 1e5 + 10;
int n; LL l;
char S[MAXN];

int TSize;
int nxt[MAXN][2];

void Insert() {
    int p = 0, len = strlen(S + 1);
    for (int i = 1; i <= len; ++i) {
        int c = S[i] - '0';
        if (nxt[p][c] == 0) nxt[p][c] = ++TSize;
        p = nxt[p][c];
    }
}

LL DFS(int u, int h = 0) {
    if (nxt[u][0] == 0 && nxt[u][1] == 0) return 0;
    LL cur = 0;
    if (nxt[u][0] != 0 && nxt[u][1] != 0) cur = 0; else
    cur = (l - h) & (h - l);
    if (nxt[u][0] != 0) cur ^= DFS(nxt[u][0], h + 1);
    if (nxt[u][1] != 0) cur ^= DFS(nxt[u][1], h + 1);
    return cur;
}

int main() {
    scanf("%d%lld", &n, &l);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", S + 1);
        Insert();
    }

    puts(DFS(0) ? "Alice" : "Bob");
    return 0;
}
