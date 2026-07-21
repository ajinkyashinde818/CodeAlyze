#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
#define R 1000000007
#define M 998244353

int mx = 0, mn = INT32_MAX;

long long power_mod_q(long long x, long long n, long long q)
{
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return power_mod_q((x * x) % q, n / 2, q);
    else 
        return (x * power_mod_q((x * x) % q, n / 2, q)) % q; 
}

struct dsu
{
    vector<int> rank, parent;
    dsu(int n)
    {
        rank.assign(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find_set(int i)
    {
        if(i == parent[i])
            return i;
        return parent[i] = find_set(parent[i]);
    }
    bool is_same_set(int i, int j)
    {
        if(find_set(i) == find_set(j))
            return true;
        return false;
    }
    void union_set(int i, int j)
    {
        if(!is_same_set(i, j))
        {
            int u = find_set(i), v = find_set(j);
            if(rank[u] == rank[v])
            {
                parent[v] = u;
                rank[u] += 1;
            }
            else if(rank[u] > rank[v])
                parent[v] = u;
            else 
                parent[u] = v;
        }
    }

};


struct graph
{
    int v, time, count;
    vector<pair<int, int>>* adj;
    vector<bool> visited, in_stack, ap;
    stack<int> s;
    vector<int> color, cc, d, f, l, finish_time, indegree, sccs, topo, outdegree, pred, child;
    graph(int n)
    {
        v = n;
        adj = new vector<pair<int, int>>[n];
        visited.assign(n, false);
        in_stack.assign(n, false);
        ap.assign(n, false);
        color.assign(n, 0);
        cc.assign(n, -1);
        d.assign(n, -1);
        f.assign(n, -1);
        indegree.assign(n, 0);
        outdegree.assign(n, 0);
        pred.assign(n, -1);
        child.assign(n, 0);
        time = count = 0;
        finish_time.assign(2 * n, -1);
        l.assign(n, 0);
    }
    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void dfs()
    {
        color.assign(v, 0);
        cc.assign(v, -1);
        time = count = 0;
        finish_time.assign(2 * v, -1);
        visited.assign(v, false);
        pred.assign(v, -1);
        for(int i = 0; i < v; i++)
        {
            if(color[i] == 0)
            {
                dfs(i);
                count++;
            }
        }
        for(int i = 0; i < v; i++)
            finish_time[f[i]] = i;
    }
    void dfs(int i)
    {
        color[i] = 1;
        cc[i] = count;
        d[i] = time;
        time++;
        for(auto x : adj[i])
            if(color[x.first] == 0)
            {
                pred[x.first] = i;
                dfs(x.first);
            }
        color[i] = 2;
        f[i] = time;
        time++;
    }

    void scc()
    {
        graph g_t(v);
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                g_t.add_edge(x.first, i, x.second);
        dfs();
        for(int i = 2 * v - 1; i >= 0; i--)
        {
            if(finish_time[i] != -1 && g_t.color[finish_time[i]] == 0)
            {
                g_t.dfs(finish_time[i]);
                g_t.count++;
            }
        }
        sccs = g_t.cc;
        count = g_t.count;
    }

    void topological_sort()
    {
        for(int i = 0; i < v; i++)
            if(adj[i].size())
                outdegree[i] = adj[i].size();
        for(int i = 0; i < v; i++)
            for(auto x : adj[i])
                indegree[x.first]++;
        vector<int> zero;
        for(int i = 0; i < v; i++)
            if(!indegree[i])
                zero.push_back(i);
        
        while(!zero.empty())
        {
            int v = zero.back();
            topo.push_back(v);
            zero.pop_back();
            for(auto x : adj[v])
            {
                indegree[x.first]--;
                if(!indegree[x.first])
                    zero.push_back(x.first);
            }
        }
    }

    void tarjan()
    {
        for(int i = 0; i < v; i++)
            if(!color[i])
                tarjan(i);
    }
    void tarjan(int i)
    {
        color[i] = 1;
        d[i] = time;
        time++;
        l[i] = d[i];
        s.push(i);
        in_stack[i] = true;
        for(auto x : adj[i])
        {
            if(!color[x.first])
            {
                tarjan(x.first);
                l[i] = min(l[i], l[x.first]);
            }
            else if(in_stack[x.first])
            {
                l[i] = min(l[i], d[x.first]);
            }
        }
        
        color[i] = 2;
        f[i] = time;
        time++;
        if(d[i] == l[i])
        {
            while(s.top() != i)
                cout << s.top() << ' ', in_stack[s.top()] = false, s.pop();
            cout << s.top() << '\n', in_stack[s.top()] = false, s.pop();
        }
    }

    void articulate()
    {
        ap.assign(v, false);
        color.assign(v, 0);
        child.assign(v, 0);
        time = 0;
        d.assign(v, -1);
        f.assign(v, -1);
        l.assign(v, 0);
        pred.assign(v, -1);
        for(int i = 0; i < v; i++)
            if(color[i] == 0)
            {
                articulate(i);
                if(child[i] == 1 || child[i] == 0)
                    ap[i] = false;
            }
    }

    void articulate(int i)
    {
        color[i] = 1;
        d[i] = time;
        time++;
        l[i] = d[i];
        for(auto x : adj[i])
        {
            if(pred[i] != x.first && color[x.first] == 1)
                l[i] = min(l[i], d[x.first]);
            if(!color[x.first])
            {
                pred[x.first] = i;
                child[i]++;
                articulate(x.first);
                l[i] = min(l[i], l[x.first]);
            }
            if(l[x.first] >= d[i])
                ap[i] = true;
            
        } 
        f[i] = time;
        time++;
        color[i] = 2;
    }

    void bridges()
    {
        time = 0;
        f.assign(v, -1);
        d.assign(v, -1);
        l.assign(v, 0);
        color.assign(v, 0);
        pred.assign(v, -1);
        for(int i = 0; i < v; i++)
            if(color[i] == 0)
                bridge(i);
    }

    void bridge(int i)
    {
        color[i] = 1;
        d[i] = time;
        time++;
        l[i] = d[i];
        for(auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
        {
            if(pred[i] != itr -> first && color[itr -> first] == 1)
                l[i] = min(l[i], d[itr -> first]);
            if(!color[itr -> first])
            {
                pred[itr -> first] = i;
                bridge(itr -> first);
                l[i] = min(l[i], l[itr -> first]);
            }
            if(l[itr -> first] > d[i])
                itr -> second = 1;
        }
        color[i] = 2;
        f[i] = time;
        time++;
    }
};

struct kmp
{
    vector<int> lps;
    string p, t;
    kmp(string& p, string& t)
    {
        this -> p = p;
        this -> t = t;
        //PREPROCESSING
        lps.assign(p.size(), 0);
        lps[0] = 0;
        int len = 0, i = 1, j;
        while(i < p.size())
        {
            if(p[i] == p[len])
                lps[i++] = ++len;
            else if(len)
                len = lps[len-1];
            else 
                lps[i++] = 0;
        }
        //STRING MATCHING
        i = j = 0;
        while(i < t.size())
        {
            if(p[j] == t[i])
                j++, i++;
            
            if(j == p.size())
                j = lps[j-1];
            else if(i < t.size() && p[j] != t[i])
            {
                if(j)
                    j = lps[j-1];
                else 
                    i++;
            }
        }

        
    }
};

struct segment_tree
{
    int n;
    string a;
    vector<bitset<26>> tree;
    segment_tree(string& a)
    {
        n = a.length();
        this -> a = a;
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    void build(int node, int l, int r)
    {
        if(l == r)
            tree[node].set(a[l] - 'a');
        else
        {
            int mid = (l + r) / 2;
            build(2 * node + 1, l, mid);
            build(2 * node + 2, mid + 1, r);
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }
    void update(int node, int l, int r, int i, char x)
    {
        if(l == r)
        {
            a[l] = a[r] = x;
            tree[node].reset();
            tree[node][a[l] - 'a'] = 1;
        }
        else
        {
            int mid = (l + r) / 2;
            if(i >= l && i <= mid)
                update(2 * node + 1, l, mid, i, x);
            else
                update(2 * node + 2, mid + 1, r, i, x);
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }
    bitset<26> query(int node, int l, int r, int s, int e)
    {
        if(l == s && r == e)
            return tree[node];
        else
        {
            int mid = (s + e) / 2;
            if(r <= mid)
                return query(2 * node + 1, l, r, s, mid);
            else if(l > mid)
                return query(2 * node + 2, l, r, mid + 1, e);
            else 
                return query(2 * node + 1, l, mid, s, mid) | query(2 * node + 2, mid + 1, r, mid + 1, e);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r;
    cin >> n >> r;
    if(n >= 10)
        cout << r << '\n';
    else 
    {
        cout << 100 * (10 - n) + r << '\n';
    }
    return 0;
}
