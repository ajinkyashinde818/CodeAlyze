// dfmt off
T lread(T=long)(){return readln.chomp.to!T;}T[] lreads(T=long)(long n){return iota(n).map!((_)=>lread!T).array;}
T[] aryread(T=long)(){return readln.split.to!(T[]);}void arywrite(T)(T a){a.map!text.join(' ').writeln;}
void scan(L...)(ref L A){auto l=readln.split;foreach(i,T;L){A[i]=l[i].to!T;}}alias sread=()=>readln.chomp();
void dprint(L...)(lazy L A){debug{auto l=new string[](L.length);static foreach(i,a;A)l[i]=a.text;arywrite(l);}}
static immutable MOD=10^^9+7;alias PQueue(T,alias l="b<a")=BinaryHeap!(Array!T,l);import std, core.bitop;
// dfmt on

void main()
{
    struct S
    {
        long zero, one, inversion;
    }

    S op(S l, S r)
    {
        return S(l.zero + r.zero, l.one + r.one, l.inversion + r.inversion + l.one * r.zero);
    }

    S mapping(bool l, S r)
    {
        if (!l)
            return r;
        return S(r.one, r.zero, r.one * r.zero - r.inversion);
    }

    long N, Q;
    scan(N, Q);
    auto A = aryread().map!(x => (x == 0) ? S(1, 0, 0) : S(0, 1, 0)).array;

    auto seg = LazySegTree!(S, op, { return S(0, 0, 0); }, bool, mapping, "(a&&!b)||(!a&&b)", {
        return false;
    })(A);
    foreach (_; 0 .. Q)
    {
        auto input = aryread!int();
        input[1]--;
        if (input[0] == 1)
        {
            seg.apply(input[1], input[2], true);
        }
        else
        {
            seg.prod(input[1], input[2]).inversion.writeln();
        }
    }
}

// --- dsu ---

struct Dsu
{
public:
    this(int n)
    {
        _n = n, parent_or_size = new int[](n);
        parent_or_size[] = -1;
    }

    int merge(int a, int b)
    {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y)
            return x;
        if (-parent_or_size[x] < -parent_or_size[y])
        {
            auto tmp = x;
            x = y;
            y = tmp;
        }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b)
    {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a)
    {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0)
            return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a)
    {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    int[][] groups()
    {
        auto leader_buf = new int[](_n), group_size = new int[](_n);
        foreach (i; 0 .. _n)
        {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        auto result = new int[][](_n);
        foreach (i; 0 .. _n)
            result[i].reserve(group_size[i]);
        foreach (i; 0 .. _n)
            result[leader_buf[i]] ~= i;
        int[][] filtered;
        foreach (r; result)
            if (r.length != 0)
                filtered ~= r;
        return filtered;
    }

private:
    int _n;
    int[] parent_or_size;
}
// --- fenwicktree ---

struct FenwickTree(T)
{
    import std.traits : isSigned, Unsigned;

    static if (isSigned!T)
    {
        alias U = Unsigned!T;
    }
    else
    {
        alias U = T;
    }
public:
    this(int n)
    {
        _n = n;
        data = new U[](n);
    }

    void add(int p, T x)
    {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n)
        {
            data[p - 1] += cast(U) x;
            p += p & -p;
        }
    }

    T sum(int l, int r)
    {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

private:
    int _n;
    U[] data;
    U sum(int r)
    {
        U s = 0;
        while (r > 0)
        {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
}
// --- internal_bit ---

int celiPow2(int n)
{
    int x = 0;
    while ((1u << x) < cast(uint)(n))
        x++;
    return x;
}
// --- internal_math ---

import std.typecons : Tuple;

ulong safeMod(long x, long m)
{
    x %= m;
    if (x < 0)
        x += m;
    return x;
}

long ctPowMod(long x, long n, int m)
{
    if (m == 1)
        return 0;
    uint _m = cast(uint) m;
    ulong r = 1;
    ulong y = safeMod(x, m);
    while (n)
    {
        if (n & 1)
            r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

bool ctIsPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 7 || n == 61)
        return true;
    if (n % 2 == 0)
        return false;
    long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    foreach (a; [2, 7, 61])
    {
        long t = d;
        long y = ctPowMod(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1)
        {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

enum bool isPrime(int n) = ctIsPrime(n);

Tuple!(long, long) invGcd(long a, long b)
{
    a = safeMod(a, b);
    if (a == 0)
        return Tuple!(long, long)(b, 0);
    long s = b, t = a, m0 = 0, m1 = 1;
    while (t)
    {
        long u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        long tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0)
        m0 += b / s;
    return Tuple!(long, long)(s, m0);
}
// --- internal_scc ---

struct CompressedSparseRow(E)
{
    import std.typecons : Tuple;

    int[] start;
    E[] elist;
    this(int n, const ref Tuple!(int, E)[] edges)
    {
        start = new typeof(start)(n + 1);
        elist = new typeof(elist)(edges.length);
        foreach (e; edges)
            start[e[0] + 1]++;
        foreach (i; 0 .. n)
            start[i + 1] += start[i];
        auto counter = start.dup;
        foreach (e; edges)
            elist[counter[e[0]]++] = e[1];
    }
}

struct SccGraphImpl
{
    import std.typecons : Tuple;
    import std.algorithm : min;

public:
    this(int n)
    {
        _n = n;
    }

    int numVerticles()
    {
        return _n;
    }

    void addEdge(int from, int to)
    {
        edges ~= Tuple!(int, edge)(from, edge(to));
    }

    Tuple!(int, int[]) sccIds()
    {
        auto g = CompressedSparseRow!(edge)(_n, edges);
        int now_ord = 0, group_num = 0;
        int[] visited;
        auto low = new int[](_n);
        auto ord = new int[](_n);
        ord[] = -1;
        auto ids = new int[](_n);
        visited.reserve(_n);
        void dfs(int v)
        {
            low[v] = ord[v] = now_ord++;
            visited ~= v;
            foreach (i; g.start[v] .. g.start[v + 1])
            {
                auto to = g.elist[i].to;
                if (ord[to] == -1)
                {
                    dfs(to);
                    low[v] = min(low[v], low[to]);
                }
                else
                {
                    low[v] = min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v])
            {
                while (true)
                {
                    int u = visited[$ - 1];
                    visited.length--;
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v)
                        break;
                }
                group_num++;
            }
        }

        foreach (i; 0 .. _n)
            if (ord[i] == -1)
                dfs(i);
        foreach (ref x; ids)
            x = group_num - 1 - x;
        return Tuple!(int, int[])(group_num, ids);
    }

    int[][] scc()
    {
        auto ids = sccIds();
        int group_num = ids[0];
        auto counts = new int[](group_num);
        foreach (x; ids[1])
            counts[x]++;
        auto groups = new int[][](ids[0]);
        foreach (i; 0 .. group_num)
            groups[i].reserve(counts[i]);
        foreach (i; 0 .. _n)
            groups[ids[1][i]] ~= i;
        return groups;
    }

private:
    int _n;
    struct edge
    {
        int to;
    }

    Tuple!(int, edge)[] edges;
}
// --- lazy_segtree ---

struct LazySegTree(S, alias op, alias e, F, alias mapping, alias composition, alias id)
{
    import std.functional : unaryFun, binaryFun;

    static if (is(typeof(e) : string))
    {
        auto unit()
        {
            return mixin(e);
        }
    }
    else
    {
        alias unit = e;
    }
    static if (is(typeof(id) : string))
    {
        auto identity()
        {
            return mixin(id);
        }
    }
    else
    {
        alias identity = id;
    }
public:
    this(int n)
    {
        auto v = new S[](n);
        v[] = unit();
        this(v);
    }

    this(ref const S[] v)
    {
        _n = cast(int) v.length;
        log = celiPow2(_n);
        size = 1 << log;
        d = new S[](2 * size);
        d[] = unit();
        lz = new F[](size);
        lz[] = identity();
        foreach (i; 0 .. _n)
            d[size + i] = v[i];
        foreach_reverse (i; 1 .. size)
            update(i);
    }

    void set(int p, S x)
    {
        assert(0 <= p && p < _n);
        p += size;
        foreach_reverse (i; 1 .. log + 1)
            push(p >> i);
        foreach (i; 1 .. log + 1)
            update(p >> i);
    }

    S get(int p)
    {
        assert(0 <= p && p < _n);
        p += size;
        foreach_reverse (i; 1 .. log + 1)
            push(p >> i);
        return d[p];
    }

    S prod(int l, int r)
    {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r)
            return unit();
        l += size;
        r += size;
        foreach_reverse (i; 1 .. log + 1)
        {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push(r >> i);
        }

        S sml = unit(), smr = unit();
        while (l < r)
        {
            if (l & 1)
                sml = binaryFun!(op)(sml, d[l++]);
            if (r & 1)
                smr = binaryFun!(op)(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return binaryFun!(op)(sml, smr);
    }

    S allProd()
    {
        return d[1];
    }

    void apply(int p, F f)
    {
        assert(0 <= p && p < _n);
        p += size;
        foreach_reverse (i; 1 .. log + 1)
            push(p >> i);
        d[p] = binaryFun!(mapping)(f, d[p]);
        foreach (i; 1 .. log + 1)
            update(p >> i);
    }

    void apply(int l, int r, F f)
    {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r)
            return;
        l += size;
        r += size;
        foreach_reverse (i; 1 .. log + 1)
        {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r)
            {
                if (l & 1)
                    all_apply(l++, f);
                if (r & 1)
                    all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        foreach (i; 1 .. log + 1)
        {
            if (((l >> i) << i) != l)
                update(l >> i);
            if (((r >> i) << i) != r)
                update((r - 1) >> i);
        }
    }

    int maxRight(alias g)(int l)
    {
        return maxRight(l, unaryFun!(g));
    }

    int maxRight(G)(int l, G g) if (isCallable!G && Parameters!(G).length == 1)
    {
        assert(0 <= l && l <= _n);
        assert(g(unit()));
        if (l == _n)
            return _n;
        l += size;
        foreach_reverse (i; 1 .. log + 1)
            push(l >> i);
        S sm = unit();
        do
        {
            while (l % 2 == 0)
                l >>= 1;
            if (!g(binaryFun!(op)(sm, d[l])))
            {
                while (l < size)
                {
                    push(l);
                    l = 2 * l;
                    if (g(binaryFun!(op)(sm, d[l])))
                    {
                        sm = binaryFun!(op)(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = binaryFun!(op)(sm, d[l]);
            l++;
        }
        while ((l & -l) != l);
        return _n;
    }

    int minLeft(alias g)(int r)
    {
        return minLeft(r, unaryFun!(g));
    }

    int minLeft(G)(int r, G g) if (isCallable!G && Parameters!(G).length == 1)
    {
        assert(0 <= r && r <= _n);
        assert(g(unit()));
        if (r == 0)
            return 0;
        r += size;
        foreach_reverse (i; 1 .. log + 1)
            push((r - 1) >> i);
        S sm = unit();
        do
        {
            r--;
            while (r > 1 && (r % 2))
                r >>= 1;
            if (!g(binaryFun!(op)(d[r], sm)))
            {
                while (r < size)
                {
                    push(r);
                    r = (2 * r + 1);
                    if (g(binaryFun!(op)(d[r], sm)))
                    {
                        sm = binaryFun!(op)(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = binaryFun!(op)(d[r], sm);
        }
        while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    S[] d;
    F[] lz;

    void update(int k)
    {
        d[k] = binaryFun!(op)(d[2 * k], d[2 * k + 1]);
    }

    void all_apply(int k, F f)
    {
        d[k] = binaryFun!(mapping)(f, d[k]);
        if (k < size)
            lz[k] = binaryFun!(composition)(f, lz[k]);
    }

    void push(int k)
    {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = identity();
    }
}
// --- math ---

import std.typecons : Tuple;

long powMod(long x, long n, long m)
{
    assert(0 <= n && 1 <= m);
    if (m == 1)
        return 0;
    ulong r = 1, y = safeMod(x, m);
    while (n)
    {
        if (n & 1)
            r = (r * y) % m;
        y = (y * y) % m;
        n >>= 1;
    }
    return r;
}

long invMod(long x, long m)
{
    assert(1 <= m);
    auto z = invGcd(x, m);
    assert(z[0] == 1);
    return z[1];
}

Tuple!(long, long) crt(long[] r, long[] m)
{
    assert(r.length == m.length);
    long r0 = 0, m0 = 1;
    foreach (i; 0 .. r.length)
    {
        assert(1 <= m[i]);
        long r1 = safeMod(r[i], m[i]);
        long m1 = m[i];
        if (m0 < m1)
        {
            auto tmp = r0;
            r0 = r1;
            r1 = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        if (m0 % m1 == 0)
        {
            if (r0 % m1 != r1)
                return Tuple!(long, long)(0, 0);
            continue;
        }
        long g, im;

        {
            auto tmp = invGcd(m0, m1);
            g = tmp[0];
            im = tmp[1];
        }
        long u1 = m1 / g;
        if ((r1 - r0) % g)
            return Tuple!(long, long)(0, 0);
        long x = (r1 - r0) / g % u1 * im % u1;
        r0 += x * m0;
        m0 *= u1;
        if (r0 < 0)
            r0 += m0;
    }
    return Tuple!(long, long)(r0, m0);
}

long floorSum(long n, long m, long a, long b)
{
    long ans;
    if (m <= a)
    {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (m <= b)
    {
        ans += n * (b / m);
        b %= m;
    }
    long y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0)
        return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floorSum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}
// --- maxflow ---

struct MFGraph(Cap)
{
    import std.typecons : Tuple;

public:
    this(int n)
    {
        _n = n;
        g = new _edge[][](n);
    }

    int addEdge(int from, int to, Cap cap)
    {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = cast(int) pos.length;
        pos ~= Tuple!(int, int)(from, cast(int)(g[from].length));
        g[from] ~= _edge(to, cast(int)(g[to].length), cap);
        g[to] ~= _edge(from, cast(int)(g[from].length) - 1, 0);
        return m;
    }

    struct edge
    {
        int from, to;
        Cap cap, flow;
    }

    edge getEdge(int i)
    {
        int m = cast(int)(pos.length);
        assert(0 <= i && i < m);
        auto _e = g[pos[i][0]][pos[i][1]];
        auto _re = g[_e.to][_e.rev];
        return edge(pos[i][0], _e.to, _e.cap + _re.cap, _re.cap);
    }

    edge[] edges()
    {
        int m = cast(int)(pos.length);
        edge[] result;
        foreach (i; 0 .. m)
            result ~= getEdge(i);
        return result;
    }

    void changeEdge(int i, Cap new_cap, Cap new_flow)
    {
        int m = cast(int)(pos.length);
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto _e = &g[pos[i][0]][pos[i][1]];
        auto _re = &g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t)
    {
        return flow(s, t, Cap.max);
    }

    Cap flow(int s, int t, Cap flow_limit)
    {
        import std.container : DList;
        import std.algorithm : min;

        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);

        auto level = new int[](_n), iter = new int[](_n);
        DList!int que;

        void bfs()
        {
            level[] = -1;
            level[s] = 0;
            que.clear();
            que.insertBack(s);
            while (!que.empty)
            {
                int v = que.front;
                que.removeFront();
                foreach (e; g[v])
                {
                    if (e.cap == 0 || level[e.to] >= 0)
                        continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t)
                        return;
                    que.insertBack(e.to);
                }
            }
        }

        Cap dfs(int v, Cap up)
        {
            if (v == s)
                return up;
            Cap res = 0;
            int level_v = level[v];
            for (; iter[v] < cast(int)(g[v].length); iter[v]++)
            {
                auto i = iter[v];
                auto e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0)
                    continue;
                Cap d = dfs(e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0)
                    continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up)
                    break;
            }
            return res;
        }

        Cap flow = 0;
        while (flow < flow_limit)
        {
            bfs();
            if (level[t] == -1)
                break;
            iter[] = 0;
            while (flow < flow_limit)
            {
                Cap f = dfs(t, flow_limit - flow);
                if (!f)
                    break;
                flow += f;
            }
        }
        return flow;
    }

    bool[] minCut(int s)
    {
        import std.container : DList;

        auto visited = new bool[](_n);
        DList!int que;
        que.insertBack(s);
        while (!que.empty)
        {
            int p = que.front;
            que.removeFront();
            visited[p] = true;
            foreach (e; g[p])
            {
                if (e.cap && !visited[e.to])
                {
                    visited[e.to] = true;
                    que.insertBack(e.to);
                }
            }
        }
        return visited;
    }

private:
    struct _edge
    {
        int to, rev;
        Cap cap;
    }

    int _n;
    Tuple!(int, int)[] pos;
    _edge[][] g;
}
// --- modint ---

struct StaticModInt(int m) if (1 <= m)
{
    import std.traits : isSigned, isUnsigned;

    alias mint = StaticModInt;
public:
    static int mod()
    {
        return m;
    }

    static mint raw(int v)
    {
        mint x;
        x._v = v;
        return x;
    }

    this(T)(T v) if (isSigned!T)
    {
        long x = cast(long)(v % cast(long)(umod()));
        if (x < 0)
            x += umod();
        _v = cast(uint)(x);
    }

    this(T)(T v) if (isUnsigned!T)
    {
        _v = cast(uint)(v % umod());
    }

    this(bool v)
    {
        _v = cast(uint)(v) % umod();
    }

    uint val()
    {
        return _v;
    }

    ref mint opUnary(string op)() pure nothrow @safe if (op == "++")
    {
        _v++;
        if (_v == umod())
            _v = 0;
        return this;
    }

    ref mint opUnary(string op)() pure nothrow @safe if (op == "--")
    {
        if (_v == 0)
            _v = umod();
        _v--;
        return this;
    }

    mint opUnary(string op)() if (op == "+" || op == "-")
    {
        mint x;
        return mixin("x " ~ op ~ " this");
    }

    ref mint opOpAssign(string op, T)(T value) if (!is(T == mint))
    {
        mint y = value;
        return opOpAssign!(op)(y);
    }

    ref mint opOpAssign(string op, T)(T value) if (op == "+" && is(T == mint))
    {
        _v += value._v;
        if (_v >= umod())
            _v -= umod();
        return this;
    }

    ref mint opOpAssign(string op, T)(T value) if (op == "-" && is(T == mint))
    {
        _v -= value._v;
        if (_v >= umod())
            _v += umod();
        return this;
    }

    ref mint opOpAssign(string op, T)(T value) if (op == "*" && is(T == mint))
    {
        ulong z = _v;
        z *= value._v;
        _v = cast(uint)(z % umod());
        return this;
    }

    ref mint opOpAssign(string op, T)(T value) if (op == "/" && is(T == mint))
    {
        return this = this * value.inv();
    }

    mint pow(long n) const
    {
        assert(0 <= n);
        mint x = this, r = 1;
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    mint inv() const
    {
        static if (prime)
        {
            assert(_v);
            return pow(umod() - 2);
        }
        else
        {
            auto eg = invGcd(_v, mod());
            assert(eg[0] == 1);
            return mint(eg[1]);
        }
    }

    mint opBinary(string op, R)(const R value) const 
            if (op == "+" || op == "-" || op == "*" || op == "/")
    {
        static if (is(R == mint))
        {
            mint x;
            x += this;
            return x.opOpAssign!(op)(value);
        }
        else
        {
            mint y = value;
            return opOpAssign!(op)(y);
        }
    }

    mint opBinaryRight(string op, L)(const L value) const if (!is(L == mint))
    {
        mint y = value;
        return y.opBinary!(op)(this);
    }

    bool opEquals(R)(const R value) const
    {
        static if (is(R == mint))
        {
            return _v == value._v;
        }
        else
        {
            mint y = mint(value);
            return this == y;
        }
    }

private:
    uint _v;
    uint umod() pure const
    {
        return m;
    }

    enum bool prime = isPrime!(m);
}

struct DynamicModInt(int id)
{
    import std.traits : isSigned, isUnsigned;

    alias mint = DynamicModInt;
public:
    static int mod()
    {
        return _m;
    }

    static void setMod(int m)
    {
        assert(1 <= m);
        _m = m;
    }

    static mint raw(int v)
    {
        mint x;
        x._v = v;
        return x;
    }

    this(T)(T v) if (isSigned!T)
    {
        long x = cast(long)(v % cast(long)(umod()));
        if (x < 0)
            x += umod();
        _v = cast(uint)(x);
    }

    this(T)(T v) if (isUnsigned!T)
    {
        _v = cast(uint)(v % umod());
    }

    this(bool v)
    {
        _v = cast(uint)(v) % umod();
    }

    uint val()
    {
        return _v;
    }

    ref mint opUnary(string op)() nothrow @safe if (op == "++")
    {
        _v++;
        if (_v == umod())
            _v = 0;
        return this;
    }

    ref mint opUnary(string op)() nothrow @safe if (op == "--")
    {
        if (_v == 0)
            _v = umod();
        _v--;
        return this;
    }

    mint opUnary(string op)() if (op == "+" || op == "-")
    {
        mint x;
        return mixin("x " ~ op ~ " this");
    }

    ref mint opOpAssign(string op, T)(T value) if (!is(T == mint))
    {
        mint y = value;
        return opOpAssign!(op)(y);
    }

    ref mint opOpAssign(string op, T)(T value) if (op == "+" && is(T == mint))
    {
        _v += value._v;
        if (_v >= umod())
            _v -= umod();
        return this;
    }

    ref mint opOpAssign(string op, T)(T value) if (op == "-" && is(T == mint))
    {
        _v -= value._v;
        if (_v >= umod())
            _v += umod();
        return this;
    }

    ref mint opOpAssign(string op, T)(T value) if (op == "*" && is(T == mint))
    {
        ulong z = _v;
        z *= value._v;
        _v = cast(uint)(z % umod());
        return this;
    }

    ref mint opOpAssign(string op, T)(T value) if (op == "/" && is(T == mint))
    {
        return this = this * value.inv();
    }

    mint pow(long n) const
    {
        assert(0 <= n);
        mint x = this, r = 1;
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    mint inv() const
    {
        auto eg = invGcd(_v, mod());
        assert(eg[0] == 1);
        return mint(eg[1]);
    }

    mint opBinary(string op, R)(const R value) const 
            if (op == "+" || op == "-" || op == "*" || op == "/")
    {
        static if (is(R == mint))
        {
            mint x;
            x += this;
            return x.opOpAssign!(op)(value);
        }
        else
        {
            mint y = value;
            return opOpAssign!(op)(y);
        }
    }

    mint opBinaryRight(string op, L)(const L value) const if (!is(L == mint))
    {
        mint y = value;
        return y.opBinary!(op)(this);
    }

    bool opEquals(R)(const R value) const
    {
        static if (is(R == mint))
        {
            return _v == value._v;
        }
        else
        {
            mint y = mint(value);
            return this == y;
        }
    }

private:
    uint _v;
    static uint _m;
    uint umod()
    {
        return _m;
    }
}

alias modint998244353 = StaticModInt!(998244353);
alias modint1000000007 = StaticModInt!(1000000007);
alias modint = DynamicModInt!(-1); // --- acl ---
// --- scc ---

struct SccGraph
{
    this(int n)
    {
        internal = SccGraphImpl(n);
    }

    void addEdge(int from, int to)
    {
        int n = internal.numVerticles();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.addEdge(from, to);
    }

    int[][] scc()
    {
        return internal.scc();
    }

private:
    SccGraphImpl internal;
}
// --- segtree ---

struct Segtree(S, alias op, alias e)
{
    import std.functional : binaryFun, unaryFun;
    import std.traits : isCallable, Parameters;

    static if (is(typeof(e) : string))
    {
        auto unit()
        {
            return mixin(e);
        }
    }
    else
    {
        alias unit = e;
    }

    this(int n)
    {
        this(new S[](n));
    }

    this(S[] v)
    {

        _n = cast(int) v.length;
        log = celiPow2(_n);
        size = 1 << log;
        d = new S[](2 * size);
        d[] = unit();
        foreach (i; 0 .. _n)
            d[size + i] = v[i];
        foreach_reverse (i; 1 .. size)
            update(i);
    }

    void set(int p, S x)
    {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        foreach (i; 1 .. log + 1)
            update(p >> i);
    }

    S get(int p)
    {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r)
    {
        assert(0 <= l && l <= r && r <= _n);
        S sml = unit(), smr = unit();
        l += size;
        r += size;
        while (l < r)
        {
            if (l & 1)
                sml = binaryFun!(op)(sml, d[l++]);
            if (r & 1)
                smr = binaryFun!(op)(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return binaryFun!(op)(sml, smr);
    }

    S allProd()
    {
        return d[1];
    }

    int maxRight(alias f)(int l)
    {
        return maxRight(l, unaryFun!(f));
    }

    int maxRight(F)(int l, F f) if (isCallable!F && Parameters!(F).length == 1)
    {
        assert(0 <= l && l <= _n);
        assert(f(unit()));
        if (l == _n)
            return _n;
        l += size;
        S sm = unit();
        do
        {
            while (l % 2 == 0)
                l >>= 1;
            if (!f(binaryFun!(op)(sm, d[l])))
            {
                while (l < size)
                {
                    l = 2 * l;
                    if (f(binaryFun!(op)(sm, d[l])))
                    {
                        sm = binaryFun!(op)(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = binaryFun!(op)(sm, d[l]);
            l++;
        }
        while ((l & -l) != l);
        return _n;
    }

    int minLeft(alias f)(int r)
    {
        return minLeft(r, unaryFun!(f));
    }

    int minLeft(F)(int r, F f) if (isCallable!F && Parameters!(F).length == 1)
    {
        assert(0 <= r && r <= _n);
        assert(f(unit()));
        if (r == 0)
            return 0;
        r += size;
        S sm = unit();
        do
        {
            r--;
            while (r > 1 && (r % 2))
                r >>= 1;
            if (!f(binaryFun!(op)(d[r], sm)))
            {
                while (r < size)
                {
                    r = 2 * r + 1;
                    if (f(binaryFun!(op)(d[r], sm)))
                    {
                        sm = binaryFun!(op)(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = binaryFun!(op)(d[r], sm);
        }
        while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    S[] d;
    void update(int k)
    {
        d[k] = binaryFun!(op)(d[2 * k], d[2 * k + 1]);
    }
}
// --- twosat ---

struct TwoSat
{
public:
    this(int n)
    {
        _n = n;
        _answer = new bool[](n);
        scc = SccGraphImpl(2 * n + 2);
    }

    void addClause(int i, bool f, int j, bool g)
    {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.addEdge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.addEdge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }

    bool satisfiable()
    {
        auto id = scc.sccIds()[1];
        foreach (i; 0 .. _n)
        {
            if (id[2 * i] == id[2 * i + 1])
                return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }

    bool[] answer()
    {
        return _answer;
    }

private:
    int _n;
    bool[] _answer;
    SccGraphImpl scc;
}
