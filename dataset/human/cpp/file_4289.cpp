#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    char c = getchar();
    int p = 1;
    x = 0;
    while(!isdigit(c)){
        if(c == '-')p = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = (x << 1) + (x << 3) + (c ^ '0');
        c = getchar();
    }
    x *= p;
}
const int maxn = 100050;
int a[maxn], n, b[maxn], ta[maxn], tb[maxn], ans, tn, tot, head[maxn];
bool flag, vis[maxn], s[maxn];
struct edge{
    int to, next;
}e[maxn << 1];
inline void add(int u, int v){
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
inline void dfs(int u){
    vis[u] = 1;
    for(register int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(!vis[v])dfs(v);
    }
}
int main(){
    //freopen(".out", "w", stdout);
    read(n);
    for(register int i = 1; i <= n; ++i){
        read(a[i]);
        a[n + 1] ^= a[i];
    }
    for(register int i = 1; i <= n; ++i){
        read(b[i]);
        b[n + 1] ^= b[i];
    }
    memset(ta, -1, sizeof(ta)), memset(tb, -1, sizeof(tb));
    for(register int i = 1; i <= n + 1; ++i){
        ta[i] = a[i];
    }
    for(register int j = 1; j <= n + 1; ++j){
        tb[j] = b[j];
    }
    sort(ta + 1, ta + 1 + n + 1), sort(tb + 1, tb + 1 + n + 1);
    for(register int i = 1; i <= n + 1; ++i){
        if(ta[i] != tb[i]){
            puts("-1");
            return 0;
        }
    }
    ++n;
    tn = unique(ta + 1, ta + 1 + n) - (ta + 1);
    tn = unique(tb + 1, tb + 1 + n) - (tb + 1);
    for(register int i = 1; i <= n; ++i){
        a[i] = lower_bound(ta + 1, ta + 1 + tn, a[i]) - (ta + 1);
        b[i] = lower_bound(tb + 1, tb + 1 + tn, b[i]) - (tb + 1);
    }
    for(register int i = 1; i <= n; ++i){
        if(a[i] != b[i] || i == n){
            if(i != n)++ans;
            add(a[i], b[i]), add(b[i], a[i]);
            s[a[i]] = s[b[i]] = 1;
        }
    }
    if(ans == 0){
        puts("0");
        return 0;
    }
    for(register int i = 1; i <= tn; ++i){
        if(!vis[i] && s[i]){
            dfs(i);
            ++ans;
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}
