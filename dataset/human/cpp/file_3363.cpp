#include<iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <queue>
#include <fstream>
#include <functional>

using namespace std;
using ll = long long;

// graph
const ll MAX_V = 1;
const ll MAX_E = 1;
struct edge {
    ll from, to, cost;
};
edge ES[MAX_E];
vector<edge> G[MAX_V];
ll d[MAX_V];
ll prev_path[MAX_V];
ll V, E;

const ll MOD = (ll) 1e9 + 7;
const int MAX_INT = 1 << 17;

vector<bool> prime;

#define all(x) (x).begin(),(x).end()
#define PRI(n) cout << n <<endl;
#define PRI2(n, m) cout << n << " " << m << " "<<endl;

#define REP(i, n)  for(int i = 0; i < (ll)n; ++i)
#define REPbit(bit, n)  for(int bit = 0; bit < (int)(1<<n); ++bit)
#define FOR(i, t, n)  for(ll i = t; i <= (ll)n; ++i)

void Era(int x) {
    prime.resize(x + 1, 1);
    prime[0] = 0;
    prime[1] = 0;
    FOR(i, 2, sqrt(x)) {
        if (prime[i]) {
            for (int j = 2 * i; j <= x; j += i) {
                prime[j] = 0;
            }
        }
    }
}

bool isPrime(ll x) {
    if (x == 0)return 0;
    if (x == 1)return 0;
    if (x == 2)return 1;
    if (x % 2 == 0)return 0;
    FOR(i, 3, sqrt(x) + 1) {
        if (x % i == 0)return 0;
    }
    return 1;
}

ll GCD(ll a, ll b) {
    if (b == 0)return a;
    return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
    ll gcd = GCD(a, b);
    return a / gcd * b;
}

ll nCr(ll n, ll r) {
    vector<ll> C(r + 1);
    C[0] = 1;
    FOR(i, 1, n)for (ll j = min(i, r); j < 1; --j)
            C[j] = (C[j] + C[j - 1]);
    return C[r];
}

template<class T>
class SegTree {
    int n;
    vector<T> data;
    T def;
    function<T(T, T)> operation;
    function<T(T, T)> update;

    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def;
        if (a <= l && r <= b)
            return data[k];
        else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return operation(c1, c2);
        }
    }

public:
    SegTree(size_t _n, T _def, function<T(T, T)> _operation,
            function<T(T, T)> _update)
            : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }

    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    T operator[](int i) {
        return data[i + n - 1];
    }
};

struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int N) {
        for (int i = 0; i < N; ++i) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (par[x] == x)return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (rank[x] < rank[y])par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y])rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

void Bellman_short(int s) {
    REP(i, V)d[i] = 1LL << 50;
    d[s] = 0;
    REP(i, V)
        REP(i, E) {
            edge e = ES[i];
            if (d[e.from] != 1LL << 50 && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
            }
        }

}

bool Bellman_negLoop(int s) {
    REP(i, V)d[i] = 1LL << 50;
    d[s] = 0;
    REP(i, V)
        REP(j, E) {
            edge e = ES[j];
            if (d[e.from] != 1LL << 50 && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (i == V - 1)return true;
            }
        }
    return false;
}

void dijkstra(int s) {
    typedef pair<ll, ll> P;
    priority_queue<P, vector<P>, greater<P>> Q;
    fill(d, d + V, LLONG_MAX);
    fill(prev_path, prev_path + V, -1);
    d[s] = 0;
    Q.push(P(0, s));
    while (!Q.empty()) {
        P p = Q.top();
        Q.pop();
        ll v = p.second;
        if (d[v] < p.first)continue;
        for (edge e:G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                Q.push(P(d[e.to], e.to));
                prev_path[e.to] = v;

            }
        }
    }
}

vector<ll> getPath(int t) {
    vector<ll> path;
    for (; t != -1; t = prev_path[t]) {
        path.push_back(t);
    }
    reverse(all(path));
    return path;
}

//
//int A[100001];
//
//bool dfs(ll x, int a) {
//    A[x] = a;
//    for (edge e : G[x]) {
//        if (e.cost % 2 == 0) {
//            if (A[e.to] == -a)return false;
//            if (A[e.to] == 0 && !dfs(e.to, a))return false;
//        } else {
//            if (A[e.to] == a)return false;
//            if (A[e.to] == 0 && !dfs(e.to, -a))return false;
//        }
//    }
//    return true;
//}



bool cp(string s) {
    PRI(s)
    if (s.size() % 2 == 0) {
        int n = s.size() / 2;
        vector<char> c;
        REP(i, n) {
            c.push_back(s[i]);
        }
        FOR(i, n, s.size() - 1) {
            if (c[i - n] != s[i])return false;
        }

        return true;
    } else {
        int n = s.size() / 2;
        vector<char> c;
        REP(i, n)c.push_back(s[i]);
        FOR(i, n + 1, s.size() - 1)if (c[i - n + 1] != c[i])return false;
        return true;
    }
}

ll N, K;

int main() {
    cin >> N;
    vector<ll> A(N);
    ll m = 0, sum = 0, l = 1e10;
    bool b = 0;
    REP(i, N) {
        cin >> A[i];
        if (A[i] < 0)m++;
        if (A[i] == 0)b = 1;
        if (abs(A[i]) > 0)l = min(l, abs(A[i]));
        sum += abs(A[i]);
    }
    if (m % 2 == 0 || b)
        PRI(sum)
    else
        PRI(sum-2*l)
    return 0;
}
