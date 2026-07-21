#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; string S;
    cin >> N >> S;
    map<char, int> cnt;
    for(int i=0; i<N; ++i) cnt[S[i]] += 1;

    const long long MOD = 1000000007;
    long long res = 1;
    for(auto p : cnt) res = (res * (p.second + 1)) % MOD;
    cout << res - 1 << endl;
}
