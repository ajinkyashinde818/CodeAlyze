#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], n;
inline int read () {
    int tot = 0, f = 1; char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar (); }
    while (c >= '0' && c <= '9') { tot = tot * 10 + c - '0'; c = getchar ();}
    return tot * f;
}
signed main () {
    n = read ();
    for (int i = 1; i <= n; i++) a[i] = read ();
    for (int i = 1; i <= n; i++) b[i] = read ();
    reverse (b + 1, b + 1 + n);
    int l = 0, r, t, L, R;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            if (l == 0) l = i, r = i, t = b[i];
            else r++;
        }
        else if (l != 0) break;
    }
    if (l == 0) {
        printf ("Yes\n");
        for (int i = 1; i <= n; i++)
            printf ("%d ", b[i]);
        return puts(""), 0;
    }
    //l~r为交集
    //L~R为并集
    for (int i = 1; i <= n; i++) if (a[i] == t || b[i] == t) { L = i - 1; break; }
    for (int i = n; i >= 1; i--) if (a[i] == t || b[i] == t) { R = i + 1; break; }
    // cout<<t<<" "<<L<<" "<<R<<endl;
    if (n - (R - L) < R - L) return puts("No"), 0;
    int pos = 1;
    for (int i = l; i <= r; i++) {
        if (pos == L + 1) pos = R;
        swap(b[i], b[pos]);
        pos++;
    }
    printf ("Yes\n");
    for (int i = 1; i <= n; i++)
        printf ("%d ", b[i]);
    return puts(""), 0;
}
