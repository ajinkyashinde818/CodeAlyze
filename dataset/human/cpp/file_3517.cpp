#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;
const int INF = 999999999;

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    ll cnt = 0;
    for(ll i = 0; i < N; i++) {
        if(A[i] >= 0) break;
        cnt++;
    }

    for(ll i = 0; i < N; i++) A[i] = abs(A[i]);
    sort(A.begin(), A.end());
    ll ans = 0;
    for(ll i = 0; i < N; i++) ans += A[i];
    if(cnt % 2 != 0) ans -= (A[0]*2);

    cout << ans << endl;

}
