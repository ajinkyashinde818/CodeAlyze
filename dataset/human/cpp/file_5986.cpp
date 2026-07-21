#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll n, c;
ll bestL[maxn], bestR[maxn], x[maxn], v[maxn];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> v[i];
    }
    bestL[0] = bestR[n+1] = 0;
    ll cur = 0;
    for(int i = 1; i <= n; i++){
        cur += v[i];
        bestL[i] = max(cur - x[i], bestL[i-1]);
    }   
    cur = 0;
    for(int i = n; i > 0; i--){
        cur += v[i];
        bestR[i] = max(cur - (c - x[i]), bestR[i+1]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, bestL[i]);
        ans = max(ans, bestR[i]);
        ans = max(ans, bestL[i] - x[i] + bestR[i+1]);
        ans = max(ans, bestR[i] - (c - x[i]) + bestL[i-1]);
    }
    cout << ans;
}
