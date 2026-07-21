// AtCoder Beginner Contest 125 - Problem D: Flipping Signs (https://atcoder.jp/contests/abc125/tasks/abc125_d)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N, const vector<ll>& as)
{
    int minus = 0;
    vector<ll> xs(N);

    for (int i = 0; i < N; ++i)
    {
        minus += (as[i] < 0 ? 1 : 0);
        xs[i] = llabs(as[i]);
    }

    ll ans = accumulate(xs.begin(), xs.end(), 0LL);
    ll m = *min_element(xs.begin(), xs.end());

    return minus % 2 == 0 ? ans : ans - 2*m;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> as(N);

    for (int i = 0; i < N; ++i)
        cin >> as[i];

    auto ans = solve(N, as);

    cout << ans << '\n';

    return 0;
}
