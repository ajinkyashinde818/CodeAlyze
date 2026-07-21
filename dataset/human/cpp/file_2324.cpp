#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int a[N];
int n;

int main() {
   // freopen("rd.txt", "r", stdin);
   // freopen("ans.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll ans = 0;
    int temp = INT_MAX;
    for (int i = 1; i <= n-1; i++) {
        if (a[i] < 0) {
            a[i+1] = -1 * a[i+1];
            a[i] = -1 * a[i];
        }
        ans = ans + 1LL * abs(a[i]);
       //temp = min(temp, abs(a[i]));
    }
   // cout << ans << " " << temp << endl;
   // temp = min(temp, abs(a[n]));
    temp = *min_element(a+1, a+n);
    if (a[n] < 0) {
       if (abs(a[n]) < temp) ans = ans + 1LL * a[n];
       else ans = ans - 1LL * a[n] - 2LL * temp;
    }
    else ans = ans + 1LL * a[n];
    printf("%lld\n", ans);
    return 0;
}
