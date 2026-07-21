#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> x(N);

    ll a = 0;
    ll b = 0;

    cin >> a;

    for(int i = 1; i < N; i++) {
        cin >> x[i];
        b += x[i];
    }

    ll ans = abs(a - b);

    for(int i = 1; i < N - 1; i++) {
        a += x[i];
        b -= x[i];
        ans = min(ans, abs(a - b));
    }

    cout << ans << endl;
}
