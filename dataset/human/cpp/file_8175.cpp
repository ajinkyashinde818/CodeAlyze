#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll INF = 1LL << 60;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> X(N);
    ll sum = 0;
    for(int i = 0;i < N;i++){
        cin >> X[i];
        sum += X[i];
    }
    ll sum2 = X[0];
    sum -= X[0];
    ll ans = abs(sum2 - sum);
    for(int i = 1;i < N-1;i++){
        sum2 += X[i];
        sum -= X[i];
        ans = min(ans, abs(sum2 - sum));
    }
    cout << ans << endl;
}
