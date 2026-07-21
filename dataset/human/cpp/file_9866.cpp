#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);

    int cnt[26] = {};

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        char q;
        cin >> q;
        ++cnt[q - 'a'];
    }

    int ans = 1;
    for(int i = 0; i < 26; ++i)
        ans = (long long) ans * (cnt[i] + 1) % MOD;

    --ans;
    if(ans < 0)
        ans += MOD;

    cout << ans << '\n';

    return 0;
}
