#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    ll l = 0,r = 0;
    int a[200010];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        r += a[i];
    }

    ll ans = 1e18;
    for(int i = 0; i < n - 1; i++){
        l += a[i],r -= a[i];
        ans = min(ans,abs(r-l));
    }

    cout << ans << endl;

    return 0;
}
