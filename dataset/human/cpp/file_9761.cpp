#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    string s;
    cin >> n >> s;
    map<char,int> mp;
    for(int i = 0; i < n; i++) mp[s[i]]++;

    ll ans = 1;

    for(auto p:mp){
        ans *= p.second+1;
        ans %= mod;
    }

    cout << ans-1 << endl;
    return 0;
}
