#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, a[N], b[N], c[N], d[N], ans;
int f[N], fa[N];
int find(int x) { return fa[x] == x?x:fa[x] = find(fa[x]); }
void merge(int x, int y) 
{ 
    x = find(x), y = find(y);
    if(x == y) return;
    fa[x] = y, f[y] += f[x]; 
} 
vector<int> s[N];
int main()
{
    n = read(), ++n;
    for(int i = 1; i < n; ++i) c[i] = a[i] = read(), c[n] = a[0] ^= a[i];
    for(int i = 1; i < n; ++i) d[i] = b[i] = read(), d[n] = b[0] ^= b[i];
    sort(c+1, c+1+n), sort(d+1, d+1+n);
    for(int i = 1; i <= n; ++i) if(c[i]^d[i]) return puts("-1"), 0;
    for(int i = 0; i < n; ++i)
        a[i] = lower_bound(c+1, c+1+n, a[i])-c,
        b[i] = lower_bound(d+1, d+1+n, b[i])-d;
    a[n] = a[0], b[n] = b[0], fa[n] = n, f[n] = -1;
    for(int i = 1; i < n; ++i) fa[i] = i, f[i] = a[i] != b[i];
    for(int i = 1; i <= n; ++i) 
        if(a[i] != b[i]||n == i)
            s[a[i]].push_back(i), merge(s[a[i]][0], i);
    for(int i = 1; i <= n; ++i) 
        if(a[i] != b[i]||n == i) merge(i, s[b[i]][0]);
    for(int i = 1; i <= n; ++i) 
        if((a[i] != b[i]||n == i)&&find(i) == i) ans += 1+f[find(i)];
    printf("%d\n", ans);
    return 0;
}
