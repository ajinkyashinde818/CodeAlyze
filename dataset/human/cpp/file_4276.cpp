#include <bits/stdc++.h>
using namespace std;

map<int, int> counter(const vector<int>& xs)
{
    map<int, int> counts;
    for (const int x : xs)
        counts[x]++;
    return counts;
}

int main()
{
    int N;
    cin >> N;

    vector<int> a(N+1);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        a[N] ^= a[i];
    }

    vector<int> b(N+1);
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
        b[N] ^= b[i];
    }

    if (counter(a) != counter(b))
    {
        cout << -1 << endl;
        return 0;
    }

    int edges = 0;
    map<int, vector<int>> out_neighbors;
    for (int i = 0; i <= N; i++)
    {
        if (i < N && a[i] == b[i]) continue;
        edges++;
        out_neighbors[a[i]].push_back(b[i]);
    }

    set<int> seen;
    const function<void(int)> dfs = [&](const int v)
    {
        seen.insert(v);
        for (const int w : out_neighbors[v])
            if (!seen.count(w))
                dfs(w);
    };

    int components = 0;
    for (const auto kv : out_neighbors)
    {
        if (seen.count(kv.first)) continue;
        else components++;
        dfs(kv.first);
    }

    cout << edges + components - 2 << endl;
}
