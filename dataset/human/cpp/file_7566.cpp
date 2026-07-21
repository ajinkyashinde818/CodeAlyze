#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1e9;

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    ll y = 0;
    for(int i = 0; i < N; ++i){
        cin >> v[i];
        y += v[i];
    }
    ll x = 0;
    ll ans = INFL;
    for(int i = 0; i < N-1; ++i){
        x += v[i];
        y -= v[i];
        ans = min(ans, llabs(x-y));
    }
    cout << ans << endl;

    return 0;
}
