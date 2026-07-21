#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn = 100010;

int n;
ll C, x[maxn];
int v[maxn];
ll pre[maxn], suf[maxn];
ll p_sum[maxn], s_sum[maxn];
ll val_p[maxn], val_s[maxn];

int main() {
    cin >> n >> C;
    ll ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) cin >> x[i] >> v[i];
    {
        for (int i = 1; i <= n; i++) {
            p_sum[i] = p_sum[i-1]+v[i];
        }
        for (int i = n; i >= 1; i--) {
            s_sum[i] = s_sum[i+1]+v[i];
        }
        for (int i = 1; i <= n; i++) {
            val_p[i] = p_sum[i]-2*x[i];
            val_s[i] = s_sum[i]-(C-x[i]);
        }
        for (int i = 1; i <= n; i++) pre[i] = max(pre[i-1], val_p[i]);
        for (int i = n; i >= 1; i--) suf[i] = max(suf[i+1], val_s[i]);
        for (int i = 0; i <= n; i++) {
            ans1 = max(ans1, pre[i]+suf[i+1]);
        }
    }
    {
        for (int i = 1; i <= n; i++) {
            p_sum[i] = p_sum[i-1]+v[i];
        }
        for (int i = n; i >= 1; i--) {
            s_sum[i] = s_sum[i+1]+v[i];
        }
        for (int i = 1; i <= n; i++) {
            val_p[i] = p_sum[i]-x[i];
            val_s[i] = s_sum[i]-2*(C-x[i]);
        }
        for (int i = 1; i <= n; i++) pre[i] = max(pre[i-1], val_p[i]);
        for (int i = n; i >= 1; i--) suf[i] = max(suf[i+1], val_s[i]);
        for (int i = 0; i <= n; i++) {
            ans2 = max(ans2, pre[i]+suf[i+1]);
        }
    }
    cout << max(ans1, ans2) << endl;
    return 0;
}
