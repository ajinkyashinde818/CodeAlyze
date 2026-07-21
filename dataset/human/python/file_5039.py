import std.stdio, std.conv, std.string, std.array, std.math, std.regex, std.range, std.ascii, std.numeric, std.random;
import std.typecons, std.functional, std.traits,std.concurrency;
import std.algorithm, std.container;
import core.bitop, core.time, core.memory;
import std.bitmanip;
import std.regex;

void main()
{
    auto N = scanElem;
    auto M = scanElem;
    struct Edge{
        long a, b;
    }
    auto edges = scanElem!Edge(M).map!(a=>Edge(a.a-1,a.b-1)).array;

    bool[] list = new bool[N];
    foreach(edge; edges)
    {
        if(edge.a==0){
            list[edge.b]=true;
        }
    }
    foreach(edge; edges)
    {
        if(edge.b==N-1&&list[edge.a]){end("POSSIBLE");
        }
    }
    end("IMPOSSIBLE");
}

//辞書順順列はiota(1,N),nextPermituionを使う

enum INF = long.max/3;
enum MOD = 10L^^9+7;

T binarySearch(alias F, T)(T ok, T ng, long iter=100)
{
    alias FF = unaryFun!F;
    foreach(_;0..iter)
    {
        auto n = (ok+ng)/2;
        if(FF(n)){
            ok = n;
        }else{
            ng = n;
        }
        static if(isIntegral!T){
            if(abs(ok-ng)==1)return ok;
        }
    }
    return ok;
}

//最小を返す
real ternarySearch(alias F)(real l, real r, long iter=200)
{
    alias FF = unaryFun!F;
    foreach(_;0..iter)
    {
        auto nl = lerp(l, r, 1/real(3));
        auto nr = lerp(l, r, 2/real(3));
        if(FF(nl)<FF(nr)){
            r = nr;
        }else{
            l = nl;
        }
    }
    return FF(l);
}
long ternarySearch(alias F)(long l, long r, long iter=200)
{
    alias FF = unaryFun!F;
    foreach(_;0..iter)
    {
        auto nl = lerp(l, r, 1/real(3)).to!long;
        auto nr = lerp(l, r, 2/real(3)).to!long;
        if(FF(nl)<FF(nr)){
            r = nr;
        }else{
            l = nl;
        }
        if(r-l<4)break;
    }
    long res=INF;
    foreach(i;l..r+1)
    {
        res = min(FF(i), res);
    }
    return res;
}

real lerp(real a, real b, real t) pure
{
    return (b-a)*t+a;
}

struct Vector{
    real x, y;

    real magnitude()pure
    {
        return sqrt(sqrMagnitude);
    }
    real sqrMagnitude()pure
    {
        return x*x+y*y;
    }

    Vector opBinary(string op, T)(inout T v)
    if(isNumeric!T)
    {
        return Vector(mixin("x"~op~"v"), mixin("y"~op~"v"));
    }
    Vector opBinary(string op)(inout Vector v)
    {
        return Vector(mixin("x"~op~"v.x"), mixin("y"~op~"v.y"));
    }
    void opOpAssign(string op, T)(inout T v)
    {
        this = mixin("this"~op~"v");
    }

    static Vector lerp(Vector a, Vector b, real t)pure
    {
        return (b-a)*t+a;
    }
    static Vector normalized(Vector a)pure
    {
        auto r = a.magnitude();
        return Vector(a.x / r, a.y / r);
    }
    static real distance(Vector a, Vector b)pure
    {
        return Vector(a.x-b.x, a.y-b.y).magnitude;
    }
    static real dot(Vector a, Vector b)pure
    {
        return a.x*b.x+a.y*b.y;
    }
    static real cross(Vector a, Vector b)pure
    {
        return a.x*b.y-b.x*a.y;
    }
}

//ascii文字のみ
long[] suffixArray(Char)(const(Char)[] s) pure
if(isSomeChar!Char)
// in{assert(s.all!"0<=a&&a<127");}
// do
{
    s ~= '\0';
    long[] p = new long[s.length];
    long[] c = new long[s.length];
    {
        long[127] cnt;
        foreach(i;0..s.length)cnt[s[i]]++;
        foreach(i;1..cnt.length)cnt[i] += cnt[i-1];
        foreach(i;0..s.length)p[--cnt[s[i]]] = i;
        long classes=1;
        foreach(i;1..p.length){
            classes += s[p[i]]!=s[p[i-1]]?1:0;
            c[p[i]] = classes-1;
        }
    }
    long[] pn = new long[s.length];
    long[] cn = new long[s.length];
    for(long n=0;(1L<<n) < s.length;n++)
    {
        p.map!(a=>mod(a-(1L<<n), s.length)).copy(pn);
        long[127] cnt;
        foreach(i;0..pn.length)cnt[c[pn[i]]]++;
        foreach(i;1..cnt.length)cnt[i] += cnt[i-1];
        foreach_reverse(i;0..pn.length)p[--cnt[c[pn[i]]]] = pn[i];
        long classes=1;
        for(long i=1;i<c.length;i++)
        {
            if(
                tuple(c[p[i]], c[(p[i]+(1L<<n))%s.length]) !=
                tuple(c[p[i-1]], c[(p[i-1]+(1L<<n))%s.length])
            ) {
                classes++;
            }
            cn[p[i]] = classes - 1;
        }
        cn.copy(c);
    }
    return p[1..$];
}

struct BiparticeMatching{
    long N;
    long[][] path;
    long[] match;
    this(long n)
    {
        N = n;
        path.length = N;
        match.length = N;
    }
    void addEdge(long u, long v){
        path[u] ~= v;
        path[v] ~= u;
    }
    long calc(){
        auto used = new bool[N];
        bool dfs(long v){
            used[v] = true;
            foreach(u; path[v]){
                long w = match[u];
                if(w==-1||(!used[w]&&dfs(w))){
                    match[v]=u;
                    match[u]=v;
                    return true;
                }
            }
            return false;
        }
        match[] = -1;
        long res = 0;
        foreach(v; 0..N){
            if(match[v] == -1){
                used[] = false;
                if(dfs(v)){
                    res++;
                }
            }
        }
        return res;
    }
}


// int max_flow(int s, int t){
//     struct edge{
//         int to, cap,  rev; 
//     }
//     edge[][MAX_V] G;
//     bool[MAX_V] used;
//     void add_edge(int from, int to, int cap){
//         G[from] ~= edge(to, cap, G[to].length);
//         G[to] ~= edge(from, 0, G[from].length-1);
//     }
//     int dfs(int v, int t, int f)
//     {
//         if(v==t)return f;
//         used[v] = true;
//         foreach(i;0..G[v].length)
//         {
//             edge e = G[v][i];
//             if(!used[e.to] && e.cap > 0){
//                 int d = dfs(e.to, t, min(f, e.cap));
//                 if(d>0){
//                     e.cap -= d;
//                     G[e.to][e.rev].cap +=d ;
//                     return d;
//                 }
//             }
//         }
//         return 0;
//     }
//     int flow = 0;
//     for(;;){
//         int f = dfs(s,t,INF);
//         if(f==0)return flow;
//         flow += f;
//     }
// }

struct CombTable2(long MOD)
{
    static long[] fac;
    static long[] finv;
    static long[] inv;
    this(long n)
    {
        fac = new long[n];
        finv = new long[n];
        inv = new long[n];

        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        foreach(i;2..n){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    long comb(long n, long k)
    {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
}
struct CombTable(long MOD, long n)
{
    static long[n] fac;
    static long[n] finv;
    static long[n] inv;
    static this()
    {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        foreach(i;2..n){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    static long comb(long n, long k)
    {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
}

void end(T)(T v)
if(isIntegral!T||isSomeString!T||isSomeChar!T||is(T==MInt))
{
    import core.stdc.stdlib;
    writeln(v);
    exit(0);
}

private long sequenceSum(long n) pure
{
    return n*(n+1)/2;
}

//HL分解
struct HeavyLightDecomposition
{
    immutable long root = 1;

    long[][] edge;
    long[] vid;
    long[] invid;
    long[] parent;
    long[] depth;
    long[] subCount;
    long[] head;

    this(long n, long root = 1)
    {
        this.root = root;
        n++;
        edge.length = n;
        vid.length = n;
        invid.length = n;
        parent.length = n; parent[] = -1;
        depth.length = n;
        head.length = n; head[root] = root;
        subCount.length = n; subCount[] = 1;
    }

    void addEdge(long u, long v)
    {
        edge[u] ~= v;
        edge[v] ~= u;
    }

    void build()
    {
        void dfs(long v){
            foreach(ref u; edge[v])
            {
                if(u==parent[v]) continue;
                parent[u] = v;
                depth[u] = depth[v] + 1;
                dfs(u);
                subCount[v] += subCount[u];
                if(edge[v][0]==parent[v]||subCount[u]>subCount[edge[v][0]])
                    swap(u, edge[v][0]);
            }
        }
        void dfsHead(long v, ref long pos){
            invid[pos] = v;
            vid[v] = pos;
            pos++;
            foreach(ref u; edge[v])
            {
                if(u==parent[v]) continue;

                head[u] = u == edge[v][0] ? head[v] : u;
                dfsHead(u, pos);
            }
        }
        dfs(root);
        long pos;
        dfsHead(root, pos);
    }

    long lca(long u, long v)
    {
        while(true){
            if(vid[u]>vid[v]) swap(u,v);
            if(head[u]==head[v]) return u;
            v = parent[head[v]];
        }
    }

    long distance(long u, long v) { return depth[u] + depth[v] - 2 * depth[lca(u,v)]; }

    //idxのn個上の親を返す
    //バグあるかも
    long nParent(long n, long idx){
        auto u = 0L;
        auto v = idx;
        while(true)
        {
            if(vid[u]>vid[v]) swap(u,v);

            immutable _u = max(vid[head[v]], vid[u]);
            immutable _v = vid[v] + 1;
            if(_v<=_u+n){
                n -= _v-_u;
            }else{
                return invid[_v-n-1];
            }

            if(head[u]==head[v]) return -1;
            v = parent[head[v]];
        }
    }

    void each(long u, long v, void delegate(long u, long v) pred)
    {
        while(true)
        {
            if(vid[u]>vid[v]) swap(u,v);
            pred(max(vid[head[v]], vid[u]), vid[v] + 1);
            if(head[u]==head[v]) return;
            v = parent[head[v]];
        }
    }

    void each(alias pred)(long u, long v)
    if(is(typeof(binaryFun!pred(0L,0L))))
    {
        while(true)
        {
            if(vid[u]>vid[v]) swap(u,v);
            binaryFun!pred(max(vid[head[v]], vid[u]), vid[v] + 1);
            if(head[u]==head[v]) return;
            v = parent[head[v]];
        }
    }
}

struct HLD{

    long[][] G;
    long[] vid, head, sub, par, dep, inv, type;

    void dfs_sz(long v) {
        foreach(ref u; G[v])
            if(u==par[v]) swap(u,G[v].back());
        if(~par[v]) G[v].popBack;

        foreach(ref u; G[v]){
            par[u]=v;
            dep[u]=dep[v]+1;
            dfs_sz(u);
            sub[v]+=sub[u];
            if(sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
        }
    }

    void dfs_hld(long v,long c,ref long pos) {
        vid[v]=pos++;
        inv[vid[v]]=v;
        type[v]=c;
        foreach(u; G[v]){
            if(u==par[v]) continue;
            head[u]=(u==G[v][0]?head[v]:u);
            dfs_hld(u,c,pos);
        }
    }

    this(long n){
        G = new long[][n];
        vid = new long[n]; vid[] = -1;
        head = new long[n];
        sub = new long[n]; sub[] = 1;
        par = new long[n]; par[] = -1;
        dep = new long[n];
        inv = new long[n];
        type = new long[n];
    }

    void add_edge(long u,long v) {
        G[u] ~= v;
        G[v] ~= u;
    }

    void build(long[] rs = [0]) {
        long c=0,pos=0;
        foreach(r; rs){
            dfs_sz(r);
            head[r]=r;
            dfs_hld(r,c++,pos);
        }
    }

    long lca(long u,long v){
        while(1){
            if(vid[u]>vid[v]) swap(u,v);
            if(head[u]==head[v]) return u;
            v=par[head[v]];
        }
    }

    long distance(long u,long v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }

    // for_each(vertex)
    // [l, r) <- attention!!
    void for_each(F)(long u, long v, F f) {
        while(1){
            if(vid[u]>vid[v]) swap(u,v);
            f(max(vid[head[v]],vid[u]),vid[v]+1);
            if(head[u]!=head[v]) v=par[head[v]];
            else break;
        }
    }

    T for_each(T, Q, F)(long u,long v,T ti,Q q,F f)
    {
        T l=ti,r=ti;
        while(1){
            if(vid[u]>vid[v]){
                swap(u,v);
                swap(l,r);
            }
            l=f(l,q(max(vid[head[v]],vid[u]),vid[v]+1));
            if(head[u]!=head[v]) v=par[head[v]];
                else break;
        }
        return f(l,r);
    }

    // for_each(edge)
    // [l, r) <- attention!!
    void for_each_edge(F)(long u, long v,F f) {
        while(1){
            if(vid[u]>vid[v]) swap(u,v);
            if(head[u]!=head[v]){
                f(vid[head[v]],vid[v]+1);
                v=par[head[v]];
            }else{
                if(u!=v) f(vid[u]+1,vid[v]+1);
                break;
            }
        }
    }
}

struct SegTree(T, T UNIT, alias pred){
    int n;
    long size;
    T* arr;
    alias F = binaryFun!pred;

    this(long size)
    {
        this.size = size;
        n=1;
        while(n<size) n<<=1;
        arr = new T[n<<1].ptr;
        arr[0..n<<1] = UNIT;
    }

    void set(long k,T x)
    {
        assert(k>=0&&k<size);

        arr[k+=n]=x;
        while(k>>=1)
            arr[k]=F(arr[(k<<1)|0],arr[(k<<1)|1]);
    }

    T query(long a, long b)
    {
        assert(a>=0&&a<size);
        assert(b>=1&&b<=size);

        T vl=UNIT,vr=UNIT;
        for(long l=a+n,r=b+n;l<r;l>>=1,r>>=1)
        {
            if(l&1) vl=F(vl,arr[l++]);
            if(r&1) vr=F(arr[--r],vr);
        }
        return F(vl,vr);
    }
}

bool isInf(Num)(Num v) pure @nogc
{
    return v>=INF/2;
}

long mod(long n, long mod) pure @nogc
{
    return (n%mod+mod)%mod;
}

long pow(long a, long n) {
    long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
long powmod(long a, long n, long mod) {
    long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

alias MInt = ModInt!MOD;

struct ModInt(alias Mod)
if(isIntegral!(typeof(Mod)) && isPrime(Mod))
{
    long value;

    this(ModInt!Mod v)
    {
        value = v.value;
    }
    this(long v)
    {
        value = mod(v, Mod);
    }

    ModInt!Mod opBinaryRight(string op, T)(inout T v) const
    if((op=="+"||op=="-"||op=="*")&&isIntegral!T)
    {
        return typeof(this)(mixin("v"~op~"value"));
    }
    ModInt!Mod opBinary(string op, T)(inout T v) const
    if((op=="+"||op=="-"||op=="*")&&(is(T==ModInt!Mod)||isIntegral!T))
    {
        return typeof(this)(mixin("value"~op~"v"));
    }

    ModInt!Mod opBinaryRight(string op, T)(inout T v) const
    if((op=="/")&&isIntegral!T)
    {
        return v * (this^^(Mod-2));
    }
    ModInt!Mod opBinary(string op, T)(inout T v) const
    if((op=="/")&&(is(T==ModInt!Mod)||isIntegral!T))
    {
        return this * (typeof(this)(v)^^(Mod-2));
    }

    ModInt!Mod opBinaryRight(string op, T)(inout T v) const
    if((op=="^^")&&isIntegral!T)
    {
        return typeof(this)(powmod(v, value, Mod));
    }
    ModInt!Mod opBinary(string op, T)(inout T v) const
    if((op=="^^")&&(is(T==ModInt!Mod)||isIntegral!T))
    {
        return typeof(this)(powmod(value, v, Mod));
    }

    void opAssign(T)(inout T v)
    if(isIntegral!T)
    {
        this = typeof(this)(v);
    }

    void opOpAssign(string op, T)(inout T v)
    {
        this = mixin("this"~op~"v");
    }

    bool opEquals(T)(const T v) const
    if(is(T==ModInt!Mod)||isIntegral!T)
    {
        return value == typeof(this)(v).value;
    }

    long opCast() const {
        return value;
    }

    string toString() const {
        return value.to!string;
    }
}
unittest
{
    assert(is(ModInt!MOD));
    assert(is(ModInt!17));
    assert(!is(ModInt!0));
    assert(!is(ModInt!10));
}

unittest
{
    alias MInt = ModInt!13;
    MInt value;
    value = MInt(14) + MInt(18);
    assert(value==6);
    value = 14 - MInt(28);
    assert(value==12);
    value = MInt(17) * -19;
    assert(value==2);

    value = MInt(7) / 4;
    assert(value==5);
    value = 8 / MInt(4);
    assert(value==2);
    value = 9;
    value /= 4;
    assert(value==12);

    assert(MInt(3) ^^ 9 == 1);
    assert(MInt(54) ^^ MInt(9) == 5);

    value = 29-MInt(16);
    assert(value==0);
    value = MInt(13)*5;
    assert(value==0);
    value = 0;
    assert(value==0);

    value = 3;
    value += MInt(11);
    assert(value==1);
    value -= 7;
    assert(value==7);
    value *= MInt(4);
    assert(value==2);
    value = 23;
    assert(value == cast(long)value);
}
unittest
{
    ModInt!MOD value;
    value = MOD-1;
    assert(value==MOD-1);
    value = MOD;
    assert(value==0);
}

struct Grid(T){
    private T[] grid;
    size_t width, height;
    private size_t stride;

    private this(T[] g, size_t w, size_t h, size_t s)
    {
        grid = g;
        width = w;
        height = h;
        stride = s;
    }

    this(size_t w, size_t h, T init = T.init)
    {
        auto arr = new T[w*h];
        arr[] = init;
        this(arr, w, h, w);
    }

    // void fill(T elem){
    //     grid[] = elem;
    // }

    bool isInRange(long x, long y) const nothrow
    {
        return 
            x>=0 &&
            x<width &&
            y>=0 &&
            y<height;
    }
    
    int opApply(scope int delegate(ref T) dg)
    {
        int result = 0;

        foreach(y;0..height)
        foreach(x;0..width)
        {
            result = dg(this[x,y]);
            if (result)
                break;
        }
        return result;
    }
    int opApply(scope int delegate(long i, ref T) dg)
    {
        int result = 0;

        long idx;
        foreach(y;0..height)
        foreach(x;0..width)
        {
            result = dg(idx++, this[x,y]);
            if (result)
                break;
        }
        return result;
    }
    int opApply(scope int delegate(long x, long y, ref T) dg)
    {
        int result = 0;

        foreach(y;0..height)
        foreach(x;0..width)
        {
            result = dg(x, y, this[x,y]);
            if (result)
                break;
        }
        return result;
    }

    ref T opIndex(long x, long y)
    {
        assert(isInRange(x,y));
        return (grid.ptr)[x+stride*y];
    }

    Grid!T opIndex(long[2] r1, long[2] r2)
    {
        auto startOffset = r1[0] + r2[0]*stride;
        auto endOffset = r1[1] + (r2[1] - 1)*stride;

        auto resGrid = grid[startOffset .. endOffset];
        auto resStride = stride;
        auto resWidth = r1[1] - r1[0];
        auto resHeight = r2[1] - r2[0];
        return Grid!T(resGrid, resWidth, resHeight, resStride);
    }
    
    Grid!T opIndex(long[2] r1, long j) { return opIndex(r1, [j, j+1]); }
    Grid!T opIndex(long i, long[2] r2) { return opIndex([i, i+1], r2); }

    long[2] opSlice(long dim)(long start, long end)
    if (dim == 0 || dim == 1)
    // in { assert(start >= 0 && end <= this.opDollar!dim); }
    body{
        return [start, end];
    }

    Grid!T transpose(){
        auto grid = Grid!T(height, width);

        foreach(w; 0..width)
        foreach(h; 0..height)
        {
            grid[h, w] = this[w, h];
        }
        return grid;
    }

    long opDollar(long dim : 0)() const { return width; }
    long opDollar(long dim : 1)() const { return height; }

    string toString() pure {
        long count;
        foreach(y; 0..height)
        {
            foreach(x; 0..width)
            {
                long eCount = this[x, y].to!string.length;
                static if(is(typeof(this[x,y].isInf)))
                {
                    if(this[x,y].isInf)
                    {
                        eCount = 1;
                    }
                }
                static if(is(typeof(this[x,y])==bool))
                {
                    eCount = 1;
                }
                count = max(count, eCount);
            }
        }
        count++;

        string res = "\n";
        foreach(y; 0..height)
        {
            foreach(x; 0..width)
            {
                string joinStr = this[x, y].to!string;
                static if(is(typeof(this[x,y].isInf)))
                {
                    if(this[x,y].isInf)
                    {
                        joinStr = "*";
                    }
                }
                static if(is(typeof(this[x,y])==bool))
                {
                    joinStr = this[x,y]?"+":"-";
                }
                foreach(i;0..count-joinStr.length)
                {
                    res ~= ' ';
                }
                res ~= joinStr;
            }
            res ~= '\n';
        }
        return res;
    }
}

struct UnionFind{
    private long[] arr;
    long rootCount;

    @disable this();
    this(long n){
        arr.length = cast(size_t)n;
        arr[] = -1;
        rootCount = n;
    }

    void merge(long a, long b)
    {
        if(same(a,b)) return;
        arr[root(a)] = root(b);
        rootCount--;
    }

    bool same(long a, long b)
    {
        return root(a)==root(b);
    }

    private long root(long a)
    {
        size_t i = cast(size_t)a;
        if(arr[i] == -1) return i;
        return arr[i] = root(arr[i]);
    }
}

unittest{
    assert(is(typeof(UnionFind(10))));
    assert(!is(typeof(UnionFind())));

    auto uf = UnionFind(10);
    uf.merge(2,3);
    assert(uf.same(2,3));
    uf.merge(3,4);
    uf.merge(1,5);
    uf.merge(5,6);
    uf.merge(6,7);
    assert(!uf.same(4,7));
    uf.merge(1,2);
    assert(uf.same(4,7));
}

void debugPrint(List...)()
{
    void _debugPrintElem(alias elem, float rad)()
    {
        import std.experimental.color;
        import std.experimental.color.lab;
        import std.experimental.color.rgb;
        import std.experimental.color.xyz;

        enum color = LCh!float(80f, 100f, rad);
        enum rgb = color.convertColor!(Lab!float).convertColor!(XYZ!float).convertColor!(RGB8).tristimulus;
        enum r = rgb[0].value;
        enum g = rgb[1].value;
        enum b = rgb[2].value;

        stderr.writef!"\033[38;2;%s;%s;%sm"(r, g, b);
        static if(isSomeFunction!elem)
        {
            stderr.write("elem: ", elem(), " ");
        }else{
            enum name =  __traits(identifier, elem);
            stderr.write(name, ": ");
            stderr.write(elem, " ");
        }
    }
    void _debugPrint(int i, float rad, List...)()
    {
        _debugPrintElem!(List[0], i * rad)();
        static if(List.length>1)
        {
            _debugPrint!(i+1, rad, List[1..$])();
        }
    }

    debug(Local)
    {
        _debugPrint!(0, 360f/List.length, List)();
        stderr.writeln("\033[0m");
    }
}


struct Stack(Elem){
    private Elem[] array;
    private size_t endIdx;

    void insertBack(Elem e)
    {
        if(endIdx==array.length){
            array.length = array.length*2+10;
        }
        (array.ptr)[endIdx++] = e;
    }

    void insertBack(Range)(Range range)
    if(is(typeof(array[0] = range.popFront)))
    {
        if(endIdx+range.length>array.length){
            array.length = (endIdx+range.length)*2+10;
        }
        foreach(ref e;range)
        {
            (array.ptr)[endIdx++] = e;
        }
    }

    Elem[] opSlice(){
        return array[0..endIdx];
    }

    void popBack()
    {
        assert(endIdx!=0);
        endIdx--;
    }

    ref Elem back()
    {
        assert(endIdx!=0);
        return (array.ptr)[endIdx-1];
    }

    size_t count() const 
    {
        return endIdx; 
    }

    bool empty() const 
    {
        return endIdx==0;
    }

    void clear()
    {
        endIdx = 0;
    }
}

Grid!T scanGrid(T=long)(long w, long h, dchar t='.')
{
    auto grid = Grid!T(w,h);
    foreach(y;0..h)
    {
        foreach(x;0..w)
        {
            grid[x, y] = scanElem!T;
        }
    }

    return grid;
}

Grid!bool scanGridBool(long w, long h, dchar t='.')
{
    auto grid = Grid!bool(w,h);
    foreach(y;0..h)
    {
        auto line = scanString;
        foreach(x;0..w)
        {
            grid[x, y] = line[x]==t;
        }
    }

    return grid;
}

T[] scanLineArray(T = long)()
{
    static char[] scanBuf;
    readln(scanBuf);
    return scanBuf.split.to!(T[]);
}

char scanChar()
{
    int c = ' ';
    while (isWhite(c) && c != -1)
    {
        c = getchar;
    }
    return cast(char)c;
}

T[] scanElem(T=long)(long size)
{
    T[] list = new T[size];
    foreach(i;0..size)
    {
        list[i] = scanElem!T;
    }
    return list;
}

T scanElem(T)()
if(is(T==struct))
{
    T res;
    foreach(ref field; res.tupleof){
        field = scanElem!(typeof(field));
    }
    return res;
}

Tuple!List[] scanElem(List...)(long size)
{
    auto list = new Tuple!List[size];
    foreach(i;0..size)
    {
        list[i] = scanElem!List;
    }
    return list;
}
Tuple!List scanElem(List...)()
{
    List res;
    foreach(i, e; List){
        res[i] = scanElem!e;
    }
    return tuple(res);
}

T scanElem(T = long)()
if(isBasicType!T||isSomeString!T)
{
    import core.stdc.stdlib;
    static auto scanBuf = appender!(char[])([]);

    scanBuf.clear;

    int c = ' ';
    while (isWhite(c) && c != -1)
    {
        c = getchar;
    }
    while (!isWhite(c) && c != -1)
    {
        scanBuf ~= cast(char) c;
        c = getchar;
    }
    return scanBuf.data.to!T;
}

string scanString(){
    return scanElem!string;
}

long gcd(long a, long b) pure
{
    if(b==0)return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) pure
{
    return a / gcd(a, b) * b;
}

struct Factor
{
    long n;
    long c;
}

//素因数分解
Factor[] factors(long n) pure
{
    Factor[] res;
    for (long i = 2; i ^^ 2 <= n; i++)
    {
        if (n % i != 0)
            continue;

        long c;
        while (n % i == 0)
        {
            n = n / i;
            c++;
        }
        res ~= Factor(i, c);
    }
    if (n != 1)
        res ~= Factor(n, 1);

    return res;
}
//約数をすべて列挙
long[] divisors(long n) pure
{
    long[] list;
    void func(Factor[] fs, long n)
    {
        if(fs.empty){
            list ~= n;
            return;
        }

        foreach(c; 0..fs[0].c+1)
        {
            func(fs[1..$], n * (fs[0].n ^^ c));
        }
    }

    func(factors(n), 1);
    sort(list);
    return list;
}
//nまでの素数のリスト
long[] primes(long n) pure
{
    if(n<2)return [];

    auto table = new long[cast(size_t)n+1];

    long[] res;
    for(size_t i = 2;i<=n;i++)
    {
        if(table[i]==-1) continue;
        for(size_t a = i;a<table.length;a+=i)
        {
            table[a] = -1;
        }
        res ~= i;
    }
    return res;
}
//素数判定
bool isPrime(long n) pure
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (long i = 3; i ^^ 2 <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

//桁を数える
long digitCount(long n, long base=10) pure
{
    long res;
    do{
        n/=base;
        res++;
    }while(n!=0);

    return res;
}
