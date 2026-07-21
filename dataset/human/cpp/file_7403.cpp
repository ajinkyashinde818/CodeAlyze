#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    ll sum = 0;
    ll ans = INF, sunuke_score = 0, bear_score = 0;

    for(int i=0; i<N; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for(int i=0; i<N-1; i++) {
        sunuke_score += a[i];
        bear_score = sum - sunuke_score;
        ans = min(ans, abs(sunuke_score-bear_score));
    }
    cout << ans << endl;
}
