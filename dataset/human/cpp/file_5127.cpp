#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll solve(int N, const vector<ll>& xs)
{
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, R;
    cin >> N >> R;

    cout << (N >= 10 ? R : R + 100*(10 - N)) << '\n';

    return 0;
}
