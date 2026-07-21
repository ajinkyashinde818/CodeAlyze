#include <iostream>
#include <string>
#include <vector>
const int MOD = 1e9 + 7;
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> f(26, 0);

    for(int i = 0; i < n; i += 1) {
        f[s[i] - 'a'] += 1;
    }
    
    int ans = 1;

    for(int i = 0; i < 26; i += 1) {
        ans = 1LL * ans * (f[i] + 1) % MOD;
    }
    
    ans -= 1;
    if(ans < 0)
        ans += MOD;
    cout << ans << "\n";
}
