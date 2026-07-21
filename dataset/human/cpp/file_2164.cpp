#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N; cin >> N;
    ll cnt = 0;
    ll sum = 0;
    ll min_abs = INT_MAX;

    for (int i = 0;i < N;i++){
        ll a; cin >> a;
        min_abs = min(abs(a),min_abs);
        sum += abs(a);
        if(a < 0) cnt++;
    }

    if(cnt%2 == 0) cout << sum << endl;
    else cout << sum - min_abs*2 << endl;

    return 0;

}
