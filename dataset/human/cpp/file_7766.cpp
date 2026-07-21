#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    ll x = 0, y = 0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        x += niz[i];
    }
    ll res = 2000000000;
    for(int i=1; i<n; i++){
        x -= niz[i];
        y += niz[i];
        res = min(res, abs(x-y));
    }
    cout << res;
    return 0;
}
