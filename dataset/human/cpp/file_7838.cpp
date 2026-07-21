#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
const ll LL_INF = 1LL<<60;

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    ll allsum = 0;
    vector<ll> sum(n+1,0);
    for(int i=0;i<n;i++){
        cin >> A[i];
        allsum += A[i];
        sum[i+1] = sum[i] + A[i];
    }
    ll ans = LL_INF;
    for(int i=1;i<n;i++){
        ll p = sum[i];
        ll q = allsum - sum[i];
        ll diff = abs(p-q);
        ans = min(ans,diff);
    }
    cout << ans << endl;


}
