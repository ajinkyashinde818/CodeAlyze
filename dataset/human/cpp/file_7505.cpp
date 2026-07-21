#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

int N;
vector<ll> A(200010, 0);
vector<ll> v(200010, 0);

int main(void){
	
	scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%lld", &A[i]);
    
    ll sum = 0;
    for(int i = 0; i < N; ++i) sum += A[i], v[i] = sum;
    
    ll ans = LLONG_MAX;
    for(int i = 0; i < N - 1; ++i){
        ll x = v[i], y = v[N - 1] - v[i];
        ans = min(ans, abs(x - y));
    }
    printf("%lld\n", ans);
    
    return 0;
}
