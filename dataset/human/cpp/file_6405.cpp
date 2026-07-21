#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
typedef pair<int,P> PP;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mod(ll val, ll M) {
    ll res = val % M;
    if(res < 0) {
        res += M;
    }
    return res;
}

template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<char> vec(2 * N);
    for(int i = 0;i < 2 * N;i++) {
        cin >> vec.at(i);
    }
    vector<int> cnt(2 * N);
    int L = 1;
    int R = 0;
    for(int i = 0;i < 2 * N - 1;i++) {
        if(vec.at(i) != vec.at(i + 1)) {
            cnt.at(i + 1) = cnt.at(i);
        }
        else {
            cnt.at(i + 1) = 1 - cnt.at(i);
        }
        if(cnt.at(i + 1) == 0) {
            L++;
        }
        else {
            R++;
        }
    }

    bool cnt2 = true;
    if(vec.at(0) == 'W' || vec.at(2 * N - 1) == 'W' || cnt.at(2 * N - 1) == 0 || L != R) {
        cnt2 = false;
    }

    if(cnt2 == false) {
        cout << 0 << endl;
    }
    else {
        ll ret = 1;
        ll Lcnt = 0;
        for(int i = 0;i < 2 * N;i++) {
            if(cnt.at(i) == 0) {
                Lcnt++;
            }
            else {
                ret *= Lcnt;
                Lcnt--;
                ret %= MOD;
            }
        }
        ll cnt3 = 1;
        for(ll i = 0;i < N;i++) {
            cnt3 *= i + 1;
            cnt3 %= MOD;
        }
        cout << ret * cnt3 % MOD << endl;
    }
}
