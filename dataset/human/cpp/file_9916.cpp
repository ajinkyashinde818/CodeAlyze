#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007;

void solve(long long N, std::string S){
    map<char, ll> cnt;
    for(int i = 0; i < (int)N; ++i) cnt[S[i]] += 1;
    ll ans = 1;
    for(auto i: cnt){
        //cout << i.first << " " << i.second << endl;;
        (ans *= (i.second + 1)) %= MOD;
    }
    cout << (ans - 1 + MOD) % MOD << endl;
    //cout << (ans - 1) % MOD << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
