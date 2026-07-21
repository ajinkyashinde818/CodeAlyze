import std.stdio, std.conv, std.string, std.array, std.math, std.regex, std.range, std.ascii, std.numeric, std.random;
import std.typecons, std.functional, std.traits;
import std.algorithm, std.container;
import core.bitop, core.time, core.memory;
import std.bitmanip;
import std.regex;

enum INF = long.max/3;
enum MOD = 10L^^9+7;

void main()
{
    auto N = scanElem;
    auto A = scanArray;
    auto B = scanArray;
    auto C = scanArray;
    A[] -= 1;
    long res;
    foreach(i;0..N)
    {
        res += B[A[i]];
        if(i>0&&A[i-1]+1==A[i]){
            res += C[A[i-1]];
        }
    }
    writeln(res);
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
if(isIntegral!T||isSomeString!T||isSomeChar!T)
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

bool isInf(Num)(Num v) pure
{
    return v>=INF/2;
}

long mod(long n, long mod) pure
{
    return (n%mod+mod)%mod;
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

    private static ModInt!Mod inv(ModInt!Mod v) pure
    {
        ModInt res=1;
        long p = Mod-2;
        while(p!=0)
        {
            if(p&1)res *= v;
            v *= v;
            p >>= 1;
        }
        return res;
    }

    ModInt!Mod opBinaryRight(string op, T)(inout T v) const
    if((op=="+"||op=="-"||op=="*")&&isIntegral!T)
    {
        return ModInt!Mod(mixin("v"~op~"value"));
    }
    ModInt!Mod opBinary(string op, T)(inout T v) const
    if((op=="+"||op=="-"||op=="*")&&(is(T==ModInt!Mod)||isIntegral!T))
    {
        return ModInt!Mod(mixin("value"~op~"v"));
    }

    ModInt!Mod opBinaryRight(string op, T)(inout T v) const
    if((op=="/")&&isIntegral!T)
    {
        return v * inv(this);
    }
    ModInt!Mod opBinary(string op, T)(inout T v) const
    if((op=="/")&&(is(T==ModInt!Mod)||isIntegral!T))
    {
        return this * inv(ModInt(v));
    }

    void opAssign(T)(inout T v)
    if(isIntegral!T)
    {
        this = ModInt!Mod(v);
    }

    void opOpAssign(string op, T)(inout T v)
    {
        this = mixin("this"~op~"v");
    }

    bool opEquals(T)(const T v) const
    if(is(T==ModInt!Mod)||isIntegral!T)
    {
        return value == ModInt(v).value;
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
    assert(MInt.inv(MInt(4))==10);
    assert(MInt.inv(MInt(6))==11);
    assert(MInt.inv(MInt(12))==12);
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

    long opDollar(long dim : 0)() const { return width; }
    long opDollar(long dim : 1)() const { return height; }

    string toString() {
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

enum TermColor{
    Blue,
    Red,
    Purple,
    Gray,
    Green,
    Brown,
    Default,
}

string termStr(TermColor c) pure
{
    switch(c)
    {
        case TermColor.Blue:   return "\033[38;2;122;158;194m";
        case TermColor.Red:    return "\033[38;2;204;130;66m";
        case TermColor.Purple: return "\033[38;2;158;123;176m";
        case TermColor.Gray:   return "\033[38;2;106;135;89m";
        case TermColor.Green:  return "\033[38;2;165;194;97m";
        case TermColor.Brown:  return "\033[38;2;204;130;66m";
        default: return "\033[0m";
    }
}

void print(TermColor C = TermColor.Gray, T...)(T t)
{
    debug(Local) stderr.write(C.termStr, t, TermColor.Default.termStr);
}
void printf(TermColor C = TermColor.Gray, T...)(T t)
{
    debug(Local) stderr.write(C.termStr);
    debug(Local) stderr.writef(t);
    debug(Local) stderr.write(TermColor.Default.termStr);
}
void println(TermColor C = TermColor.Gray, T...)(T t)
{
    debug(Local) stderr.writeln(C.termStr, t, TermColor.Default.termStr);
}
void printfln(TermColor C = TermColor.Gray, T...)(T t)
{
    debug(Local) stderr.write(C.termStr);
    debug(Local) stderr.writefln(t);
    debug(Local) stderr.write(TermColor.Default.termStr);
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
}

T[] scanArray(T = long)()
{
    static char[] scanBuf;
    readln(scanBuf);
    return scanBuf.split.to!(T[]);
}

dchar scanChar()
{
    import core.stdc.stdlib;
    int c = ' ';
    while (isWhite(c) && c != -1)
    {
        c = getchar;
    }
    return cast(dchar)c;
}

T scanElem(T = long)()
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

dchar[] scanString(){
    return scanElem!(dchar[]);
}

template fold(fun...) if (fun.length >= 1)
{
    auto fold(R, S...)(R r, S seed)
    {
        static if (S.length < 2)
        {
            return reduce!fun(seed, r);
        }
        else
        {
            import std.typecons : tuple;

            return reduce!fun(tuple(seed), r);
        }
    }
}

long lcm(long a, long b) pure
{
    return a * b / gcd(a, b);
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
