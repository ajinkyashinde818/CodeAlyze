#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
const ll LINF = 1ll << 55;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};


/// cin/cout overload
template<typename T>
ostream& operator<< (ostream& out, vector<T>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        out << *it << " ";
    }
    return out;
}

template<typename T>
ostream& operator<< (ostream& out, pair<T, T>& P) {
    out << P.first << " " << P.second;
    return out;
}

template<typename T>
istream& operator>> (istream& in, vector<T>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        in >> *it;
    }
    return in;
}

template<typename T>
istream& operator>> (istream& in, pair<T, T>& P) {
    in >> P.first >> P.second;
    return in;
}

/// 图相关
//ll N, M;
//
// struct Edge {
//    ll to;
//    ll weight;
//    ll next;
//    bool operator<(const Edge& rhs) {
//        return weight < rhs.weight;
//    }
// };

struct Edge2 {
   ll u, v, w;
   Edge2(ll u_, ll v_, ll w_) : u(u_), v(v_), w(w_) {}
   Edge2() : u(0ll), v(0ll), w(0ll) {}
   bool operator<(const Edge2& rhs) {
       return w < rhs.w;
   }
};

// vector<Edge> edges(MAXN);
//vector<ll> head(MAXN, -1);
//vector<int> matchingx(MAXN, -1);
//vector<int> matchingy(MAXN, -1);
//vector<bool> check(MAXN);
//vector<ll> dis(MAXN);
//vector<bool> vis(MAXN, false);
//
//ll cnt = 1;
//
//void addEdge(ll from, ll to, ll weight) {
//    edges[cnt].to = to;
//    edges[cnt].weight = weight;
//    edges[cnt].next = head[from];
//    head[from] = cnt++;
//}
//
//bool dfs(int u) {
//    for (int i = head[u]; i != -1; i = edges[i].next) {
//        int v = edges[i].to;
//        if (!check[v]) {
//            check[v] = true;
//            if (matchingy[v] == -1 || dfs(matchingy[v])) {
//                matchingy[v] = u;
//                matchingx[u] = v;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int hungarian() {
//    int ans = 0;
//    fill(matchingx.begin(), matchingx.end(), -1);
//    fill(matchingy.begin(), matchingy.end(), -1);
//    for (int u = 1; u <= N; ++u) {
////        if (matchingx[u] == -1) {
//        {
//            fill(check.begin(), check.end(), false);
//            if (dfs(u)) {
//                ++ans;
//            }
//        }
//    }
//    return ans;
//}
//
//void dijkstra(const ll s) {
//    priority_queue<P, vector<P>, greater<P>> que;
//    fill(dis.begin(), dis.end(), INF);
//    dis[s] = 0;
//    que.push(P(0, s));
//////multiple sources
////    for (auto& x : shops) {
////        dis[x] = 0;
////        que.push(P(0, x));
////    }
//    while (!que.empty()) {
//        P p = que.top();
//        que.pop();
////        cout << "pop " << p.second << endl;
//        int u = p.second;
//        if (dis[u] < p.first) continue;
//        for (int i = head[u]; i != -1; i = edges[i].next) {
//            int v = edges[i].to;
//            if (dis[v] > dis[u] + edges[i].weight) {
//                dis[v] = dis[u] + edges[i].weight;
////                cout << "push " << v << endl;
//                que.push(P(dis[v], v));
//            }
//        }
//    }
//}

//void zeroOneBFS(const int s) {
//    deque<P> que;
//    fill(dis.begin(), dis.end(), INF);
//    dis[s] = 0;
//    que.push_front(P(0, s));
//    while (!que.empty()) {
//        P p = que.front();
//        que.pop_front();
//        int u = p.second;
//        if (dis[u] < p.first) continue;
//        for (int i = head[u]; i != -1; i = edges[i].next) {
//            int v = edges[i].to;
//            if (dis[v] > dis[u] + edges[i].weight) {
//                dis[v] = dis[u] + edges[i].weight;
//                if (edges[i].weight) {
//                    que.push_back(P(dis[v], v));
//                } else {
//                    que.push_front(P(dis[v], v));
//                }
//            }
//        }
//    }
//}
//
//struct TreeNode {
//    int val;
//    TreeNode* left = nullptr;
//    TreeNode* right = nullptr;
//    TreeNode(int val_) : val(val_) {}
//};
//
////int dfs(int cur, int a, int b, int c, const vector<int> &nums) {
////    if (cur >= N) {
////        return (min({a, b, c}) > 0 ? (abs(a - A) + abs(b - B) + abs(c - C) - 30) : INF);
////    }
////    int ret0 = dfs(cur + 1, a, b, c, nums);
////    int ret1 = dfs(cur + 1, a + nums[cur], b, c, nums) + 10;
////    int ret2 = dfs(cur + 1, a, b + nums[cur], c, nums) + 10;
////    int ret3 = dfs(cur + 1, a, b, c + nums[cur], nums) + 10;
////    return min({ret0, ret1, ret2, ret3});
////}
//


//struct HuffmanNode : std::enable_shared_from_this<HuffmanNode> {
//    typedef std::shared_ptr<HuffmanNode> HuffmanNodePtr;
//    int weight;
//    HuffmanNodePtr leftChild;
//    HuffmanNodePtr rightChild;
//    HuffmanNodePtr parent;
//    explicit HuffmanNode(int weight_) : weight(weight_), leftChild(nullptr), rightChild(nullptr) {}
//    bool operator<(const HuffmanNode &rhs) const {
//        return weight > rhs.weight;
//    }
//};
//
////struct cmp {
////    bool operator () (const HuffmanNodePtr x, const HuffNode* y) {
////        return x->weight > y->weight;
////    }
////};
//
//class KthLargest {
//public:
//    KthLargest(int k, vector<int> nums) {
//        this->k = k;
//        for (auto &x : nums) {
//            add(x);
//        }
//    }
//
//    int add(int val) {
//        maxHeap.push(-val);
//        if (maxHeap.size() > k) {
//            maxHeap.pop();
//        }
//        return -maxHeap.top();
//    }
//private:
//    priority_queue<int> maxHeap;
//    int k;
//};
//
//
//int bfs() {
//    queue<P> que;
//    for (int i = 0; i < MAXN; ++i) {
//        for (int j = 0; j < MAXN; ++j) {
//            dis[i][j] = INF;
//        }
//    }
//    dis[sx][sy] = 0;
//    que.push(P(sx, sy));
//    while (!que.empty()) {
//        auto p = que.top();
//        que.pop();
//        if (p.first == gx && p.second == gy) break;
//        for (int i = 0; i < 4; ++i) {
//            int nx = p.first + dx[i];
//            int ny = p.second + dy[i];
//            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && dis[nx][ny] == INF) {
//                que.push(P(nx, ny));
//                dis[nx][ny] = dis[p.first][p.second] + 1;
//            }
//        }
//    }
//    return dis[gx][gy];
//}
//
// Union-Find 并查集
class UnionFind {
   vector<ll> parent;
public:
   explicit UnionFind(ll n) : parent(n, -1) {}

   ll find(ll a) {
       if (parent[a] < 0) {
           return a;
       }
       return parent[a] = find(parent[a]);
   }

   ll size(ll a) {
       return -parent[find(a)];
   }

   void unite(ll a, ll b) {
       a = find(a);
       b = find(b);
       if (a != b) {
           if (size(a) < size(b)) {
               swap(a, b);
           }
           parent[a] += parent[b];
           parent[b] = a;
       }
   }
};

ll kruskal(vector<Edge2>& edges2, const ll V) {
    sort(edges2.begin(), edges2.end());
    UnionFind uf(V + 10);
    ll res = 0;
    Edge2 e;
    for (int i = 0; i < edges2.size(); ++i) {
        e = edges2[i];
        if (uf.find(e.u) != uf.find(e.v)) {
            uf.unite(e.u, e.v);
            res += e.w;
        }
    }
    return res;
}

/// 线段树
//struct SegmentTreeNode {
//    ll maxVal;
//    ll minVal;
//    ll sum;
//    ll len;
//    ll lazy;
//    ll left, right;
//    SegmentTreeNode() {}
//};
//
//class SegmentTree {
//public:
//    explicit SegmentTree(size_t size, const vll& nums) : tree(size << 2), nums(nums) {
//
//    }
//    void build(ll root, ll left, ll right) {
//        tree[root].lazy = 0;
//        tree[root].left = left;
//        tree[root].right = right;
//        tree[root].len = right - left + 1;
//        if (left == right) {
//            tree[root].maxVal = nums[left];
//            tree[root].minVal = nums[left];
//            tree[root].sum = nums[left];
//        } else {
//            ll mid = (right - left) / 2 + left;
//            build(root * 2, left, mid);
//            build(root * 2 + 1, mid + 1, right);
//            tree[root].minVal = min(tree[root * 2].minVal, tree[root * 2 + 1].minVal);
//            tree[root].maxVal = max(tree[root * 2].maxVal, tree[root * 2 + 1].maxVal);
//            tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
//        }
//    }
//
//    void pushup(ll root) {
//        tree[root].minVal = min(tree[root * 2].minVal, tree[root * 2 + 1].minVal);
//        tree[root].maxVal = max(tree[root * 2].maxVal, tree[root * 2 + 1].maxVal);
//        tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
//    }
////// add single node val
//    void add(ll root, ll id, ll addVal) {
//        if (tree[root].left == tree[root].right) {
//            tree[root].maxVal += addVal;
//            tree[root].minVal += addVal;
//            tree[root].sum += addVal;
//            return;
//        }
//        ll mid = (tree[root].right - tree[root].left) / 2 + tree[root].left;
//        if (id <= mid) {
//            add(root * 2, id, addVal);
//        } else {
//            add(root * 2 + 1, id, addVal);
//        }
//        pushup(root);
//    }
//
//    void pushdown(ll root) {
//        if (tree[root].lazy) {
//            tree[root * 2].lazy += tree[root].lazy;
//            tree[root * 2 + 1].lazy += tree[root].lazy;
//            tree[root * 2].sum += tree[root * 2].len * tree[root].lazy;
//            tree[root * 2 + 1].sum += tree[root * 2 + 1].len * tree[root].lazy;
//            tree[root * 2].maxVal += tree[root].lazy;
//            tree[root * 2 + 1].maxVal += tree[root].lazy;
//            tree[root * 2].minVal += tree[root].lazy;
//            tree[root * 2 + 1].minVal += tree[root].lazy;
//            tree[root].lazy = 0;
//        }
//    }
//    //// query range sum
//    ll querySum(ll root, ll left, ll right) {
//        if (tree[root].left >= left && tree[root].right <= right) {
//            return tree[root].sum;
//        }
//        if (tree[root].left > right || tree[root].right < left) {
//            return 0;
//        }
//        if (tree[root].lazy) {
//            pushdown(root);
//        }
//        return querySum(root * 2, left, right) + querySum(root * 2 + 1, left, right);
//    }
//    //// query range max/min
//    ll queryMax(ll root, ll left, ll right) {
//        if (tree[root].left >= left && tree[root].right <= right) {
//            return tree[root].maxVal;
//        }
//        if (tree[root].left > right || tree[root].right < left) {
//            return -INF;
//        }
//        if (tree[root].lazy) {
//            pushdown(root);
//        }
//        return max(queryMax(root * 2, left, right), queryMax(root * 2 + 1, left, right));
//    }
//
//    ll queryMin(ll root, ll left, ll right) {
//        if (tree[root].left >= left && tree[root].right <= right) {
//            return tree[root].minVal;
//        }
//        if (tree[root].left > right || tree[root].right < left) {
//            return INF;
//        }
//        if (tree[root].lazy) {
//            pushdown(root);
//        }
//        return min(queryMin(root * 2, left, right), queryMin(root * 2 + 1, left, right));
//    }
//    //// add range val
//    void update(ll root, ll left, ll right, ll addVal) {
//        if (tree[root].left >= left && tree[root].right <= right) {
//            tree[root].lazy += addVal;
//            tree[root].sum += tree[root].len * addVal;
//            tree[root].maxVal += addVal;
//            tree[root].minVal += addVal;
//            return;
//        }
//        if (tree[root].left > right || tree[root].right < left) {
//            return;
//        }
//        if (tree[root].lazy) {
//            pushdown(root);
//        }
//        update(root * 2, left, right, addVal);
//        update(root * 2 + 1, left, right, addVal);
//        pushup(root);
//    }
//
//
//private:
//    vector<SegmentTreeNode> tree;
//    const vll &nums;
//};

/// 组合数

////約数求める //約数
//void divisor(ll n, vector<ll> &ret) {
//    for (ll i = 1; i * i <= n; i++) {
//        if (n % i == 0) {
//            ret.push_back(i);
//            if (i * i != n) ret.push_back(n / i);
//        }
//    }
//    sort(ret.begin(), ret.end());
//}
////階乗
//ll factorial(ll n, ll mod) {
//    ll ret = 1;
//    for (ll i = 1; i <= n; i++) {
//        ret = (ret * i) % mod;
//    }
//    return ret;
//}
////モジュラ逆数
//ll inv_mod(ll n, ll mod) {
//    ll a = n % mod, b = mod - 2, ret = 1;
//    while (b > 0) {
//        if (b & 1) ret = (ret * a) % mod;
//        a = (a * a) % mod;
//        b >>= 1;
//    }
//    return ret;
//}
//
//ll nPr(ll n, ll r, ll mod) {
//    ll ret = 1;
//    for (ll i = n; i >= n - r + 1; i--) {
//        ret = ret * (i % mod) % mod;
//    }
//    return ret;
//}
//
//ll nCr(ll n, ll r, ll mod) {
//    return nPr(n, r, mod) * inv_mod(factorial(r, mod), mod) % mod;
//}
//
//vll F(MAXN), Finv(MAXN), inv(MAXN);
//
//ll pow_mod(ll a, ll b, ll p) {
//    ll ret = 1;
//    while (b) {
//        if (b & 1) ret = (ret * a) % p;
//        a = (a * a) % p;
//        b >>= 1;
//    }
//    return ret;
//}
//
//void comb_init() {
//    inv[1] = 1;
//    for (int i = 2; i < MAXN; ++i) {
//        inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
//    }
//    F[0] = Finv[0] = 1;
//    for (int i = 1; i < MAXN; ++i) {
//        F[i] = F[i-1] * 1ll * i % MOD;
//        Finv[i] = Finv[i-1] * 1ll * inv[i] % MOD;
//    }
//}
//
//inline ll comb(ll n, ll m) {
//    if (m < 0 || m > n) return 0;
//    return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
//}
//
inline ll add_mod(ll a, ll b) {
   return (a + b) % MOD;
}

inline ll mul_mod(ll a, ll b) {
   return a * b % MOD;
}

inline ll sub_mod(ll a, ll b) {
   return (a + MOD - b) % MOD;
}

/// 自定义类型以及hash
struct UVK {
    ll u;
    ll v;
    ll k;
    UVK(ll u_, ll v_, ll k_) : u(u_), v(v_), k(k_) {}
    bool operator< (const UVK& rhs) const {
        return (u < rhs.u) || (u == rhs.u && v < rhs.v) || (u == rhs.u && v == rhs.v && k < rhs.k);
    }
};

struct UVKHash {
    ll operator() (const UVK& uvk) const {
        return ((hash<ll>()(uvk.u) ^ (hash<ll>()(uvk.v) << 1)) >> 1) ^ (hash<ll>()(uvk.k) << 1);
    }
};

struct UVKComparator {
    bool operator() (const UVK& x, const UVK& y) const {
        return x.u == y.u && x.v == y.v && x.k == y.k;
    }
};

/// AC自动机，禁止字符串
//const ll maxnode = 100 + 20;
//ll sigma_size;//后面读入
//
//struct AC_Automata
//{
//    ll ch[maxnode][100+20];
//    ll match[maxnode];
//    ll f[maxnode];
//    map<char, ll> mp;
//    ll sz;
//    void init()
//    {
//        sz=1;
//        memset(ch[0],0,sizeof(ch[0]));
//        match[0]=f[0]=0;
//        mp.clear();
//    }
//    void insert(string s)
//    {
//        ll n = s.size();
//        ll u = 0;
//        for(int i=0;i<n;i++)
//        {
//            ll id = mp[s[i]];
//            if(ch[u][id]==0)
//            {
//                ch[u][id]=sz;
//                memset(ch[sz],0,sizeof(ch[sz]));
//                match[sz++]=0;
//            }
//            u=ch[u][id];
//        }
//        match[u]=1;
//    }
//    void getFail()
//    {
//        f[0]=0;
//        queue<ll> q;
//        for(int i=0;i<sigma_size;i++)
//        {
//            ll u=ch[0][i];
//            if(u)
//            {
//                f[u]=0;
//                q.push(u);
//            }
//        }
//        while(!q.empty())
//        {
//            ll r=q.front();q.pop();
//            for(ll i=0;i<sigma_size;i++)
//            {
//                ll u=ch[r][i];
//                if(!u) { ch[r][i]=ch[f[r]][i]; continue; }
//                q.push(u);
//                ll v = f[r];
//                while (v && ch[v][i] == 0) v=f[v];
//                f[u] = ch[v][i];
//                match[u] |= match[f[u]];
//            }
//        }
//    }
//};
//AC_Automata ac;
//vector<vector<ll>> dp(MAXN, vector<ll>(MAXN));
//
//int main()
//{
//    // 字符集数目
//    ll n = 4;
//    // 字符串长度
//    ll m;
//    // 禁止字符串个数
//    ll p = 9;
//    string str;
//    cin >> m;
//    sigma_size=n;
//    ac.init();
//    // 初始化字符
//    str = "AGCT";
//    for(int i=0;i<n;i++)
//        ac.mp[str[i]]=i;
//    // 插入禁止字符串
//    ac.insert("AGC");
//    ac.insert("ACG");
//    ac.insert("GAC");
//    ac.insert("AGGC");
//    ac.insert("ACGC");
//    ac.insert("ATGC");
//    ac.insert("AGAC");
//    ac.insert("AGGC");
//    ac.insert("AGTC");
//    ac.getFail();
//
//    dp[0][0] = 1;
//    for(int k=0;k<m;k++)
//    {
//        for(int i=0;i<ac.sz;i++)
//            if(ac.match[i]==0)
//                for(int j=0;j<sigma_size;j++)
//                    if(ac.match[ac.ch[i][j]]==0)
//                        dp[ac.ch[i][j]][k+1] = add_mod(dp[ac.ch[i][j]][k+1],dp[i][k]);
//    }
//    ll ans = 0;
//    for(int i=0;i<ac.sz;i++)if(ac.match[i]==0)
//            ans = add_mod(ans,dp[i][m]);
//    cout << ans << endl;
//
//    return 0;
//}

/// ConvexHullTrick
// class ConvexHullTrick {
//     vll A, B;
//     ll len = 0;

//     inline bool check(ll a, ll b) {
//         return (B[len - 2] - B[len - 1]) * (a - A[len - 1]) >= (B[len - 1] - b) * (A[len - 1] - A[len - 2]);
//     }

//     inline ll get(ll k, ll x) {
//         return A[k] * x + B[k];
//     }

// public:
//     explicit ConvexHullTrick(ll n) : A(n), B(n) {}

//     void addline(ll a, ll b) {
//         while (len >= 2 && check(a, b)) {
//             --len;
//         }
//         A[len] = a;
//         B[len] = b;
//         ++len;
//     }

//     ll query(ll x) {
//         ll l = -1;
//         ll r = len - 1;
//         while (r - l > 1) {
//             ll mid = (r - l) / 2 + l;
//             if (get(mid, x) >= get(mid + 1, x)) {
//                 l = mid;
//             } else {
//                 r = mid;
//             }
//         }
//         return get(r, x);
//     }
// };

// /// 求逆序
// ll getInversePair(vector<ll>& nums, int start, int end, vector<ll>& copy) {
//     if (start >= end) {
//         return 0;
//     }
//     int mid = (end - start) / 2 + start;
//     ll leftCnt = getInversePair(nums, start, mid, copy);
//     ll rightCnt = getInversePair(nums, mid + 1, end, copy);
//     int p = start;
//     int q = mid + 1;
//     int index = start;
//     ll cnt = 0;
//     while (p <= mid && q <= end) {
//         if (nums[p] <= nums[q]) {
//             copy[index++] = nums[p++];
//             cnt += end - q + 1;
//         } else {
//             copy[index++] = nums[q++];
//         }
//     }
//     while (p <= mid) copy[index++] = nums[p++];
//     while (q <= end) copy[index++] = nums[q++];
//     for (int i = start; i <= end; ++i) {
//         nums[i] = copy[i];
//     }
//     return (leftCnt + rightCnt + cnt);
// }

int parseNum(string& s, int& i) {
    int res = 0;
    while (i < s.size() && isdigit(s[i])) {
        res = res * 10 + s[i] - '0';
        ++i;
    }
    return res;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else if (n > 0) {
        int res = 1;
        for (int i = 1; i <= n; ++i) {
            res *= i;
        }
        return res;
    }
    return 1;
}

int calculate(string& s, int& i) {
    // edge case
    if (s.empty()) {
        return 0;
    }
    char op = '+';
    int num = 0;
    int res = 0;
    vector<int> buffer;
    for (; i < s.size() && op != ')'; ++i) {
        if (s[i] == ' ') {
            continue;
        }
        if (isdigit(s[i])) {
            num = parseNum(s, i);
        }
        cout << num << endl;
        if (s[i] == '(') {
            num = calculate(s, ++i);
        }
        if (op == '+') {
            buffer.push_back(num);
        } else if (op == '-') {
            buffer.push_back(-num);
        } else if (op == '*') {
            buffer.back() = buffer.back() * num;
        } else if (op == '/') {
            buffer.back() = buffer.back() / num;
        } else if (op == '^') {
            buffer.back() = pow(buffer.back(), num);
        } else if (op == '!') {
            buffer.back() = factorial(buffer.back());
        }
        op = s[i];
        cout << op << endl;
        if (i == s.size() - 1 && op == '!') {
            buffer.back() = factorial(buffer.back());
        }
    }
    for (auto& x : buffer) {
        res += x;
    }
    return res;
}

class Solution {
public:
    int calculate(string s) {
        // edge case
        if (s.empty()) {
            return 0;
        }
        int index = 0;
        return parseExpr(s, index);
    }
private:
    int parseNum(string& s, int& i) {
        int res = 0;
        while (i < s.size() && isdigit(s[i])) {
            res = res * 10 + s[i++] - '0';
        }
        return res;
    }
    
    int parseExpr(string& s, int& i) {
        vector<int> buffer;
        int num = 0;
        char op = '+';
        for (; i < s.size() && op != ')'; ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (isdigit(s[i])) {
                num = parseNum(s, i);
            }
            cout << num << endl;
            if (s[i] == '(') {
                num = parseExpr(s, ++i);
            }
            if (s[i] == '+') {
                buffer.push_back(num);
            } else if (s[i] == '-') {
                buffer.push_back(-num);
            }
            op = s[i];
            cout << op << endl;
        }
        int res = 0;
        for (auto& x : buffer) {
            res += x;
        }
        return res;
    }
};

class SnapShot {
private:
    unordered_map<int, map<int, int>> m;
    vector<int> curr;
    int version = 1;
public:
    SnapShot(int size) : curr(size) {
        for (int i = 0; i < size; ++i) {
            m[i][version] = 0;
        }
    }
    void set(int index, int value) {
        if (curr[index] != value) {
            curr[index] = value;
            m[index][version] = value;
        }
    }
    int get(int index, int ver) {
        if (ver == version) {
            return curr[index];
        }
        auto it = m[index].upper_bound(ver);
        --it;
        return it->second;
    }
    void takeSnapShot() {
        ++version;
    }
};


unordered_map<string, vector<string>> tree;
unordered_set<string> dead;

void birth(string parent, string name) {
    if (tree.count(parent)) {
        tree[parent].push_back(name);
        tree[name] = {};
    }
}

void death(string name) {
    dead.insert(name);
}

void dfs(string& root, vector<string>& res) {
    if (!dead.count(root)) {
        res.push_back(root);
    }
    for (auto& child : tree[root]) {
        dfs(child, res);
    }
}

vector<string> getOrder() {
    string root = "King";
    vector<string> res;
    dfs(root, res);
    return res;
}

void init() {
    tree["King"] = {};
    birth("King", "first");
}

/// main函数
int main() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    ll ans = 0;
    for (int i = 0; i <= 3000; ++i) {
        for (int j = 0; j <= 3000; ++j) {
            int remain = n - i * r - j * g;
            if (remain % b == 0 && remain >= 0)
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
