#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll c;
ll x[100050], v[100050];
ll rsum[100050],lsum[100050];
ll r2sum[100050], l2sum[100050];

int main() {
    cin >> n >> c;
    r2sum[0] = rsum[0] = l2sum[n+1] = lsum[n+1] = 0;
    ll res = 0;
    for(int i = 1; i <= n; i++) cin >> x[i] >> v[i];
    for(int i = 1; i <= n; i++){
        rsum[i] = rsum[i-1] + v[i];
    }
    for(int i = 1; i <= n; i++){
        rsum[i] -= x[i];
        r2sum[i] = max(r2sum[i-1], rsum[i]-x[i]);
        res = max(res, rsum[i]);
    }
    for(int i = 1; i <= n; i++){
        x[i] = c - x[i];
    }
    for(int i = n; i >= 1; i--){
        lsum[i] = lsum[i+1] + v[i];
    }

    for(int i = n; i >= 1; i--){
        lsum[i] -= x[i];
        l2sum[i] = max(l2sum[i+1], lsum[i] - x[i]);
    }
    for(int i = 1; i <= n; i++){
        res = max(res, lsum[i] + r2sum[i-1]);
        res = max(res, rsum[i] + l2sum[i+1]);
    }
    cout << res;



    return 0;
}
