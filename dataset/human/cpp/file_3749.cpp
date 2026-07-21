#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef long double ld;

struct pkt
{
    ld x, y;
};

struct kolo
{
    pkt s;
    ld r;
};

struct kraw
{
    int b;
    ld c;
};

ld Dl(pkt a, pkt b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld Koszt(kolo a, kolo b)
{
    if (Dl(a.s, b.s) > a.r + b.r)
        return Dl(a.s, b.s) - a.r - b.r;
    return 0.0;
}

void Dijkstra(vector< vector<kraw> >& G, int start, vector<ld>& D)
{
    D[start] = 0.0;
    set< pair<ld, int> > Q;
    int n = G.size();
    Q.insert({D[0], 0});
    while (!Q.empty())
    {
        pair<ld, int> t = *Q.begin();
        Q.erase(Q.begin());
        for (int i = 0; i < G[t.second].size(); ++i)
        {
            if (t.first + G[t.second][i].c < D[G[t.second][i].b])
            {
                Q.erase({D[G[t.second][i].b], G[t.second][i].b});
                D[G[t.second][i].b] = t.first + G[t.second][i].c;
                Q.insert({D[G[t.second][i].b], G[t.second][i].b});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    pkt A, B;
    cin >> A.x >> A.y >> B.x >> B.y;
    int n;
    cin >> n;
    vector<kolo> K(n);
    for (int i = 0; i < n; ++i)
        cin >> K[i].s.x >> K[i].s.y >> K[i].r;
    vector< vector<kraw> > G(n + 2);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j)
                G[i + 1].push_back({j + 1, Koszt(K[i], K[j])});
    for (int i = 0; i < n; ++i)
    {
        ld d1;
        if (Dl(A, K[i].s) <= K[i].r)
            d1 = 0.0;
        else
            d1 = Dl(A, K[i].s) - K[i].r;
        G[0].push_back({i + 1, d1});
        G[i + 1].push_back({0, d1});
        ld d2;
        if (Dl(B, K[i].s) <= K[i].r)
            d2 = 0.0;
        else
            d2 = Dl(B, K[i].s) - K[i].r;
        G[n + 1].push_back({i + 1, d2});
        G[i + 1].push_back({n + 1, d2});
    }
    vector<ld> D(n + 2, 1e18 + 10);
    Dijkstra(G, 0, D);
    cout.setf(std::ios_base::fixed);
    cout.precision(15);
    cout.setf(std::ios_base::showpoint);
    ld odp = D[n + 1];
    if (Dl(A, B) < odp)
        odp = Dl(A, B);
    cout << odp;
    return 0;
}
