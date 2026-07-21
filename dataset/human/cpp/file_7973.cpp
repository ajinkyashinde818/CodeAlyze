#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    vector<ll> sum(N+1,0);
    for(int i=0; i<N; i++) cin>>A[i];
    for(int i=1; i<=N; i++){
        sum[i] = sum[i-1]+A[i-1];
    }

    ll ans = LLONG_MAX;

    for(int i=1; i<N; i++){
        ll left = sum[i];
        ll right = sum[N] - sum[i];
        ans = min(ans,abs(left-right));
    }

    cout<<ans<<endl;

    return 0;
}
