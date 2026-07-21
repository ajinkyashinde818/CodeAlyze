#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main(){
    ll N; cin >> N;
    vector<ll> A(N);
    ll sum=0, ans = INF;

    for(int i=0;i<N;++i){
        cin  >> A[i];
        sum += A[i];
    }
    ll snuke = A[0];
    ans = min(ans, abs(snuke - (sum - snuke)));
    for(int i=1;i<N-1;++i){
        snuke += A[i];
        ans = min(ans, abs(snuke - (sum - snuke)));
    }
    cout << ans << endl;
}
