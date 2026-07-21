#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

typedef pair<ll, ll> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int N;
    ll sum = 0, tmp1=inf, tmp2 = 0;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += abs(a[i]);
        if (a[i] <= 0) tmp2++;
        tmp1 = min(tmp1, abs(a[i]));
    }
    if (tmp2 % 2) sum -= 2*tmp1;
    cout << sum << endl;

    return 0;
}
