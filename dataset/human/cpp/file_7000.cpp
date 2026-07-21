#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 200005;
int a[N], b[N], c[N];
int vis[N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], c[a[i]]++;
    for (int i = 0; i < n; i++) cin >> b[i], c[b[i]]++;
    for (int i = 1; i <= n; i++) {
        if (c[i] > n) {
            return puts("No"), 0;
        }
    }
    reverse(b, b + n);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            vis[i] = 1;
            while (a[pos] == a[i] || b[pos] == a[i] || vis[pos]) pos++;
            swap(b[pos], b[i]);
            pos++;
        }
    }
    puts("Yes");
    for (int i = 0; i < n; i++) printf("%d%c", b[i], " \n"[i + 1 == n]);
    return 0;
}
