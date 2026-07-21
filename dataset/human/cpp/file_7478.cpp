#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    vector<ll> sum(N);
    sum[0] = a[0];
    for (int i = 1; i < N; i++){
        sum[i] = sum[i-1] + a[i];
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < N-1; i++){
        ll x = sum[i];
        ll y = sum[N-1] - sum[i];
        ans = min(ans,abs(x-y));
    }
    cout << ans << endl;









    return 0;
}
