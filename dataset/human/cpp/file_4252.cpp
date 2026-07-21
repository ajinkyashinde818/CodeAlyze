#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

int ans, n, i, xor_sum, nr = 0, a[Nmax], b[Nmax];
map<int,int> cnt, ord;
bool ok = 1, used[Nmax];
vector<int> v[Nmax];

void add_edge(int x, int y)
{
    v[ord[x]].push_back(ord[y]);
}

void dfs(int node)
{
    used[node] = 1;
    for(auto x : v[node])
        if(!used[x]) dfs(x);
}

int main()
{
  //  freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n;
    for(i=1; i<=n; ++i) cin >> a[i], xor_sum ^= a[i];
    for(i=1; i<=n; ++i) cin >> b[i];

    for(i=1; i<=n; ++i)
        if(a[i] == b[i])
        {
            swap(a[i], a[n]);
            swap(b[i], b[n]);
            --n; --i;
        }

    if(!n)
    {
        cout << 0 << '\n';
        return 0;
    }

    for(i=1; i<=n; ++i)
        ++cnt[a[i]], --cnt[b[i]];

    cnt[xor_sum]++;
    for(auto it : cnt) ord[it.first] = ++nr;

    for(auto it : cnt)
    {
        if(!it.second) continue;
        if(ok && it.second == 1) add_edge(xor_sum, it.first), ok = 0;
            else
            {
                cout << -1 << '\n';
                return 0;
            }
    }

    ans = n - 1;
    for(i=1; i<=n; ++i) add_edge(a[i], b[i]);

    for(i=1; i<=nr; ++i)
        if(!used[i])
        {
            dfs(i);
            ans++;
        }

    cout << ans << '\n';

    return 0;
}
