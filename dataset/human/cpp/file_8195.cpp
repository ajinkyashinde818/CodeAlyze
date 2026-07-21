#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vec<ll> A(N);
    ll sum = 0;
    vec<ll> S(N+1);
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
        S[i+1] = S[i]+A[i];
    }
    ll ans = 1e18;
    for(int i=0;i+1<N;i++){
        ans = min(ans,abs(S[i+1]-(sum-S[i+1])));
    }
    cout << ans << "\n";
}
