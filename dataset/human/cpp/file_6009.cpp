#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll N, C;
ll left1[110000], right1[110000];
ll left2[110000], right2[110000];
ll x[110000], v[110000];

int main(){
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> v[i] >> x[i];
    }
    ll ma = 0LL, x_sum = 0LL, ma2 = 0LL;
    for(int i = 0; i < N; i++){
        x_sum += x[i];
        ma = max(x_sum - v[i], ma);
        ma2 = max(x_sum - 2*v[i], ma2);
        left1[i] = ma;
        left2[i] = ma2;
    }

    ma = 0LL;
    ma2 = 0LL;
    x_sum = 0LL;
    for(int i = N-1; i >= 0; i--){
        x_sum += x[i];
        ma = max(x_sum - (C - v[i]), ma);
        ma2 = max(x_sum - 2*(C - v[i]), ma2);
        right1[i] = ma;
        right2[i] = ma2;
    }

    ll res = 0;
    for(int i = 0; i < N; i++){
        res = max(left1[i], res);
        res = max(right1[i], res);
    }
    for(int i = 0; i < N-1; i++){
        res = max(left1[i] + right2[i+1], res);
        res = max(left2[i] + right1[i+1], res);
    }

    cout << res << endl;


    return 0;

}
