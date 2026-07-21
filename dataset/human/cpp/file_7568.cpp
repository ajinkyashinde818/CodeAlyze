#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(long long N, std::vector<long long> a){
    ll sum=0;
    for(ll i=0; i< N; i++) sum+= a[i];
    ll diff = sum, ans = 1LL << 60;
    for(ll i=0; i<N-1; i++){
        diff -= a[i]*2;
        ans = min(ans, abs(diff));
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
