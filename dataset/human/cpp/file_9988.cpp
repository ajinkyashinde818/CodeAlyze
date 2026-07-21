#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 62;
const ll MODULO = 1e9+7;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> d;
    // cout << s << endl;
    long long res = 1;
    for (int i=0; i<n; i++) {
        d[s[i]]++;
    }
    for (int i=0; i<26; i++) {
        res *= d[char('a' + i)] + 1;
        res %= MODULO;
    }
    res--;
    cout << res << endl;
    return 0;
}
