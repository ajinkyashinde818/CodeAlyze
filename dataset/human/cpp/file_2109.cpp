#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<ll> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<ll> dp1(N);
    vector<ll> dp2(N);

    dp1[1] = A[0] + A[1];
    dp2[1] = - A[0] - A[1];

    for(int i = 2; i < N; i++) {
        ll a = dp1[i - 1] + A[i];
        ll b = dp2[i - 1] + A[i];
        if(a > b) {
            dp1[i] = a;
        } else {
            dp1[i] = b;
        }

        ll c = dp1[i - 1] - 2LL * A[i - 1] - A[i];
        ll d = dp2[i - 1] + 2LL * A[i - 1] - A[i];
        if(c > d) {
            dp2[i] = c;
        } else {
            dp2[i] = d;
        }
    }

    if(dp1[N - 1] > dp2[N - 1]) {
        cout << dp1[N - 1] << endl;
    } else {
        cout << dp2[N - 1] << endl;
    }
}
