#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    string a;
    int n;
    cin >> n >> a;
    vector<ll> wyst(26, 0);
    for (int i = 0; i < n; ++i)
        ++wyst[a[i] - 'a'];
    ll odp = 1;
    for (int i = 0; i < 26; ++i)
        odp = (odp * (wyst[i] + 1)) % MOD;
    --odp;
    if (odp < 0)
        odp += MOD;
    cout << odp;
    return 0;
}
