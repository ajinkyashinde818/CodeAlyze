#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;



int main(){
    int N; string S; cin >> N >> S;
    vector<ll> num(26);
    for(auto ch : S) num[(int)ch-97]++;
    ll ans = 1;
    for(int i = 0; i < 26; i++) { ans*=(num[i]+1);ans%=MOD;}
    cout << ans -1 << endl;
}
