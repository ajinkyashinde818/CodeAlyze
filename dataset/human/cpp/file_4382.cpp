#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

map<int, int>mp;
map<int, int>fa;

int a[MAXN];
int b[MAXN];

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline int Merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return 0;
    fa[fx] = fy;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    int n, Xor = 0, flag = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++, Xor ^= a[i];
    a[n + 1] = Xor, mp[Xor]++;
    for(int i = 1; i <= n; i++) {
        int &x = b[i];
        cin >> x;
        if(!mp[x]) return puts("-1"), 0;
        mp[x]--;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i]) {
            fa[a[i]] = a[i];
            fa[b[i]] = b[i];
        }
    } fa[Xor] = Xor;
    int res = fa.size();
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i])
            res -= Merge(a[i], b[i]), ++res;
    } res--;
    cout << res << endl;
    return 0;
}
