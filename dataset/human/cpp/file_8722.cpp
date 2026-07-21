#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

const int SIZE = 3e2 + 10;
const int N = 1e4 + 10;
const int NN = 1e3 + 10;

struct AC {
    int ch[N][SIZE];
    int sz;
    int f[N];
    bool ed[N];
    int last[N];
    int vt[N][SIZE];
    int vn[N];
    int co[NN][NN];

    int newnode() {
        memset(ch[sz], 0, sizeof(ch[sz]));
        ed[sz] = false;
        f[sz] = 0;
        last[sz] = 0;
        vn[sz] = 0;
        return sz++;
    }

    void init() {
        memset(co, 0, sizeof(co));
        sz = 0;
        newnode();
    }

    void insert(int id, char *s) {
        int u = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            int idx = s[i];
            if (!ch[u][idx])
                ch[u][idx] = newnode();
            u = ch[u][idx];
        }
        ed[u] = true;
        vt[u][vn[u]++] = id;
    }

    void getfail() {
        queue<int> q;
        for (int i = 0; i < SIZE; i++)
            if (ch[0][i])
                q.push(ch[0][i]);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < SIZE; i++) {
                int v = ch[u][i];
                if (v) {
                    q.push(v);
                    int r = f[u];
                    while (r && !ch[r][i])
                        r = f[r];
                    f[v] = ch[r][i];
                    last[v] = (ed[f[v]] ? f[v] : last[f[v]]);
                }
                else {
                    ch[u][i] = ch[f[u]][i];
                }
            }
        }
    }

    void print(int r, int j, int c) {
        if (j) {
            for (int i = 0; i < vn[j]; i++)
                if (r >= vt[j][i])
                    co[r - vt[j][i]][c]++;
            print(r, last[j], c);
        }
    }

    void find(int r, char *s) {
        int u = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            int idx = s[i];
            u = ch[u][idx];
            if (ed[u]) print(r, u, i);
            else if (last[u]) print(r, last[u], i);
        }
    }

}ac;

char Mat[NN][NN];

int main() {

        int n, m, x, y;
        scanf("%d ", &n);scanf("%d ", &x);
        m=n;
        for (int i = 1; i <= n; i++)
            scanf("%s", Mat[i]);
        ac.init();

        y=x;
        for (int i = 1; i <= x; i++) {
            char str[SIZE];
            scanf("%s", str);
            if (x <= n && y <= m)
                ac.insert(i, str);
        }
        int ans = 0;
        if (x <= n && y <= m) {
            ac.getfail();
            for (int i = 1; i <= n; i++)
                ac.find(i, Mat[i]);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (ac.co[i][j] == x)
                        ans++;
        }
        puts(ans?"Yes":"No");
    return 0;
}
