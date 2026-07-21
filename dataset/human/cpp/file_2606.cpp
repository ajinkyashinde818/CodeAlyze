#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    bool has0 = false;
    int minus = 0;
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        if(v[i] == 0) has0 = true;
        if(v[i] < 0) {
            minus++;
            v[i] *= -1;
        }
        ans += v[i];
    }
    if(has0 || minus % 2 == 0)
        cout << ans;
    else {
        sort(v.begin(), v.end());
        ans -= v[0] * 2;
        cout << ans;
    }
    return 0;
}
