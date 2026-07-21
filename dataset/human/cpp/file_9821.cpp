#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;


int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<ll> v(26, 0);
    ll sum = 1;
    for(int i=0;i<n;i++) {
        v[s[i] - 'a']++;
    }
    for(int i = 0; i<26;i++) {
        sum = (sum * (v[i] + 1)) % MOD;
    }
    cout << ((sum  + MOD - 1) % MOD )<< endl;
    return 0;
}
