#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double long dl;
typedef pair < int , int > pii;
typedef pair < pii, pii > p2i;
const int maxn = (int) 3e5 + 1;
const int mod = (int) 1e9 + 7;
const ll inf = (ll)1e18;

#define fi first
#define se second
#define acel ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define next continue
#define getsz(x) (int) log10(x)

int n;
ll d;
ll a[maxn], b[maxn], c[maxn], mx1[maxn], mx2[maxn];
ll cur, p[maxn], s[maxn], ans;
int main(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        p[i] = p[i - 1] + b[i];
        cur += b[i];
        mx1[i] = max(mx1[i - 1], (cur - a[i]) - a[i]);
    }
    for(int i = n; i >= 1; i--){
        s[i] = s[i + 1] + b[i];
    }
    cur = 0;
    for(int i = 1; i <= n; i++){
        c[i] = d - a[i];
    }
    for(int i = n; i >= 1; i--){
        cur += b[i];
        mx2[i] = max(mx2[i + 1], (cur - c[i]) - c[i]);
    }
    for(int i = 1; i <= n; i++){
        ans = max(ans, max({ p[i] - a[i], s[i] - c[i], p[i] + mx2[i + 1] - a[i], s[i] + mx1[i - 1] - c[i]}) );
    }
    cout << ans;
}
