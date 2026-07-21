#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 2e9;

int main(){
    int n, a, mi, count;
    ll ans;
    mi = INF;
    ans = 0;
    count = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        mi = min(mi,abs(a));
        ans += abs(a);
        if(a<0) count++;
    }
    if(count%2==1) ans -= 2*mi;
    cout << ans << endl;
}
