#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 1;
    ll k = 0;
    for(int i = 0; i < n * 2; i++){
        if((s[i] == 'B' && k % 2 == 1) || (s[i] == 'W' && k % 2 == 0)){
            ans = ans * k % MOD;
            k--;
        }
        else k++;
    }
    for(ll i = 1; i <= n; i++) ans = ans * i % MOD;
    if(k) cout << 0 << endl;
    else cout << ans << endl;
}
