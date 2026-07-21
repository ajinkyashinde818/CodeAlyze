#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N; cin >> N;
    ll a[200005];
    ll sum = 0;

    for (int i = 0;i < N;i++){
        cin >> a[i];
        sum += a[i];
    } 

    ll sum2 = 0;
    ll min_abs = LLONG_MAX;

    for (int i = 0;i < N-1;i++){
        sum2 += a[i];
        min_abs = min(min_abs,abs(sum - sum2*2));
    }

    cout << min_abs << endl;

    return 0;

}
