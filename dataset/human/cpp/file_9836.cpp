#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000000 + 7;

int main(){
    int N; cin >> N;
    string s; cin >> s;
    vector<int> v(27, 0);
    int cnt = 0, acnt = 0;
    for (int i = 0; i < N; i++){
        int m = s[i] - 'a'; 
        if(v[m]==0) cnt++;
        acnt++;
        v[m]++;
    }

    ll ans = 1;
    //cout << cnt << endl;
    for (int i = 0; i < 27; i++) 
    {
        ans *= 1+v[i];
        ans %= mod;
    }
    ans--;    
    cout << ans << endl;
}
