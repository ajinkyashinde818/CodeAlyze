#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

typedef pair<int, int> pii;

int N, K, xr;
int a[100005], b[100005];
int v[100005], w[100005];
vector <int> edg[100005];
vector <pii> edges;
multiset <int> mst;
int grd[100005];
int f[100005];

void answer(int x) { printf("%d\n", x); exit(0); }

void DFS(int nod)
{
    if(f[nod])  return;
    f[nod] = 1;
    for(auto x: edg[nod])
        DFS(x);
}

class Normalizator
{
public:
    map<int, int> mp;
    vector <int> ord;

    void add(int x)
    {
        if(mp.count(x)) return;
        mp[x];
        ord.push_back(x);
    }

    void normalize()
    {
        sort(ord.begin(), ord.end());
        for(int i = 0; i < ord.size(); i++)
            mp[ ord[i] ] = i + 1;
    }

    int get(int x) { return mp[x]; }
}nrm;

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
        v[i] = a[i];
        xr ^= a[i];
    }
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &b[i]);
        w[i] = b[i];
    }

    v[N + 1] = xr;
    sort(v + 1, v + N + 2);
    sort(w + 1, w + N + 1);
    v[N + 2] = 1 << 30;

    int cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        if(w[i] != v[i + cnt])
        {
            cnt++;
            if(w[i] != v[i + cnt])  cnt++;
            if(cnt > 1) answer(-1);
        }
    }

    nrm.add(xr);
    for(int i = 1; i <= N; i++) nrm.add(a[i]);

    nrm.normalize();

    xr = nrm.get(xr);
    for(int i = 1; i <= N; i++) a[i] = nrm.get(a[i]);
    for(int i = 1; i <= N; i++) b[i] = nrm.get(b[i]);

    mst.insert(xr);
    for(int i = 1; i <= N; i++)
    {
        if(a[i] == b[i])    continue;
        edges.push_back({b[i], a[i]});
        mst.insert(a[i]);
    }

    for(int i = 1; i <= N; i++)
    {
        if(a[i] == b[i])    continue;
        mst.erase(mst.find(b[i]));
    }

    int str = xr;
    int lst = *(mst.begin());

    edges.push_back({lst, str});

    for(auto e: edges)
    {
        grd[e.first]++;
        grd[e.second]--;
        edg[e.first].push_back(e.second);
    }

    cnt = edges.size();
    for(int i = 1; i <= nrm.ord.size(); i++)
        if(grd[i] > 0)  cnt += grd[i];

    for(int i = 1; i <= nrm.ord.size(); i++)
        if(!f[i] && !edg[i].empty())
        {
            cnt++;
            DFS(i);
        }
    cnt--;

    printf("%d\n", cnt - 1);

    return 0;
}
