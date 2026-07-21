#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    map<char,int> m;
    
    for(int i = 0; i < n; ++i) {
        m[s[i]]++;
    }
    
    ll ans = 1;
    
    for(map<char,int>::iterator it = m.begin(); it != m.end(); ++it) {
        ans *= (ll)it->second + 1;
        ans %= 1000000007;
    }
    
    cout << ans-1 << endl;
    
    return 0;
}
