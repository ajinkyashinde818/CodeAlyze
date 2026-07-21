#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int C = 26, mod = 1e9+7; int n, g[C]; string s; ll m = 1;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cin >> n >> s;

    for (auto c: s)
        g[c-'a']++;

    for (int i = 0; i < C; ++i)
        if (g[i])
            m *= ll(g[i]+1), m %= mod;

    cout << m-1;
}
