#include<bits/stdc++.h>

using namespace std;

int nr, N, a[100009], b[100009], t[200009];
pair < int, int > c[100009], d[100009];
map < int, int > mp;

int code (int x)
{
    if (mp.count (x)) return mp[x];
    return mp[x] = ++nr;
}

void checkPossibility ()
{
    for (int i=1; i<=N + 1; i++)
        c[i] = {a[i], i}, d[i] = {b[i], i};
    sort (c + 1, c + N + 2), sort (d + 1, d + N + 2);
    for (int i=1; i<=N + 1; i++)
        if (c[i].first != d[i].first)
        {
            printf ("-1\n");
            exit (0);
        }
}

int tata (int x)
{
    if (t[x] == x) return x;
    return t[x] = tata (t[x]);
}

vector < pair < int, int > > edges;
void unite (int x, int y)
{
    edges.push_back ({x, y});
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), a[N + 1] ^= a[i];
for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]), b[N + 1] ^= b[i];
checkPossibility ();
for (int i=1; i<=N + 1; i++)
    if (a[i] != b[i] || i == N + 1)
        unite (code (a[i]), code (b[i]));
for (int i=1; i<=nr; i++)
    t[i] = i;
int ans = 0, comps = nr;
for (int i=1; i<=N; i++)
    ans += (a[i] != b[i]);
for (auto it : edges)
    if (tata (it.first) != tata (it.second))
        comps --, t[tata (it.first)] = tata (it.second);
printf ("%d\n", ans + comps - 1);
return 0;
}
