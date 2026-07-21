#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<long long int> alphabet(26);
    for(int i=0; i<n; i++){
        alphabet[s[i] - 'a'] += 1;
    }

    long long int ans = 1;
    for(int i=0; i<26; i++){
        ans *= (alphabet[i] + 1);
        ans %= MOD;
    }
    ans -= 1;
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
    return 0;
}
