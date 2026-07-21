#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

int N;
string S;
map<char, int> mp;

void Input() {
    cin >> N >> S;
    for(char a = 'a'; a <= 'z'; a++) mp[a] = 0;
    return;
}

int main() {
    Input();
    for (char c : S) { mp[c]++; }
    long long ans = 1;
    for (char a = 'a'; a <= 'z'; a++) {
        ans *= (mp[a]+1);
        ans %= MOD;
    }
    cout << ans-1 << endl;
    return 0;
}
