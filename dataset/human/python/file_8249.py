import std.stdio, std.conv, std.string, std.array, std.math, std.regex, std.range, std.ascii, std.numeric, std.random;
import std.typecons, std.functional, std.traits;
import std.algorithm, std.container;
import core.stdc.stdlib, core.bitop;

void main()
{
    auto N = scanElem;
    auto list = scanArray;

    if(list.sum%sequenceSum(N)!=0){
        writeln("NO");
        return;
    }
    auto count = list.sum/sequenceSum(N);

    long c;
    foreach(i;0..N)
    {
        if(list[i] - list[i%N]==count)continue;
        auto a = (list[(i+1)%N] - list[i]-count);
        if(a>0||(a*-1)%N!=0){
            writeln("NO");
            return;
        }
        c+=(a*-1)/N;
    }
    if(c!=count){
        writeln("NO");
        return;
    }
    writeln("YES");
}

struct PascalTriangle(Int=long)
if(is(Int==typeof(Int.init+Int.init)))
{
    private Int[] arr;

    Int cmb(long n, long r){
        assert(n>=r);
        return arr[idx(r, n-1)];
    }

    this(long height)
    {
        arr.length = sequenceSum(height+2);
        arr[0] = 1;
        foreach(y;0..height)
        {
            foreach(x;0..y+1){
                arr[idx(x+0,y+1)]+=arr[idx(x,y)];
                arr[idx(x+1,y+1)]+=arr[idx(x,y)];
            }
        }
    }

    private long idx(long x, long y) pure
    {
        return sequenceSum(y)+x;
    }
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
            vid[v] = pos++;
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

    void each(alias pred)(long u, long v)
    if(is(typeof(binaryFun!pred(u,v))))
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

struct RMQ(T)
{
    alias STree = SegTree!(long, -1L);

    T[] arr;
    STree tree;

    bool delegate(T,T) F;
    this(InputRange)(InputRange range, bool delegate(T,T) f)
    if(isInputRange!InputRange)
    {
        this.arr = range.array;
        F = f;

        tree = STree(iota(0, arr.length), (a,b){
            if(a==-1)return b;
            if(b==-1)return a;
            return F(arr[a], arr[b])?a:b;
        });
    }
    this(long n, bool delegate(T,T) f)
    {
        arr.length = n;
        F = f;

        tree = STree(iota(0, n), (a,b){
            if(a==-1)return b;
            if(b==-1)return a;
            return F(arr[a], arr[b])?a:b;
        });
    }

    void build()
    {
        tree.build();
    }
    void set(long i, T value)
    {
        arr[i] = value;
        tree.set(i, i);
    }
    void update(long i, T value)
    {
        arr[i] = value;
        tree.update(i, i);
    }
    T get(long s, long t)
    {
        return arr[tree.get(s,t)];
    }
    long getIndex(long s, long t)
    {
        return tree.get(s,t);
    }
}
unittest{
    assert(is(RMQ!(long)));
    assert(is(RMQ!(Tuple!(int, string))));
    assert(!is(RMQ!(Tuple!(int, string), "a[0]<b[0]")));
}
unittest{
    struct Data{
        long i, v;
    }
    alias RmQ = RMQ!(Data);
    auto rmq = RmQ([Data(0,2), Data(1,3), Data(2,1), Data(3,0)], (a,b)=>a.v<b.v);
    assert(rmq.getIndex(0,3)==2);
    assert(rmq.get(0,3)==Data(2,1));
    assert(rmq.get(0,4)==Data(3,0));
    rmq.update(3, Data(3, 99));
    assert(rmq.get(0,4)==Data(2,1));
}

struct SegTree(T, T UNIT, alias pred="")
if(
    (is(typeof(pred)==string)&&pred=="")||
    is(T==typeof(binaryFun!pred(T.init,T.init))))
{
    T[][] tree;
    long N;
    long level;

    debug bool isBuild;

    static if((is(typeof(pred)==string)&&pred=="")){
        T delegate(T,T) F;

        this(InputRange)(InputRange arr, T delegate(T,T) f)
        if(isInputRange!InputRange&&hasLength!InputRange)
        {
            F = f;
            init(arr);
        }

        this(long n, T delegate(T,T) f)
        {
            F = f;
            init(n);
        }
    }else{
        alias F = binaryFun!pred;
        this(InputRange)(InputRange arr)
        if(isInputRange!InputRange&&hasLength!InputRange)
        {
            init(arr);
        }

        this(long n)
        {
            init(n);
        }
    }

    private void init(InputRange)(InputRange arr)
        if(isInputRange!InputRange&&hasLength!InputRange)
    {
            init(arr.length);
            arr.copy(tree[$-1][0..arr.length]);
            build();
    }

    private void init(long n){
        while(2^^level<n){
            level++;
        }
        N = 2^^level;
        level++;
        tree.length = level;

        foreach(i; 0..level)
        {
            tree[i].length = 2^^i;
        }

        tree[$-1][] = UNIT;
    }
    void build(){
        debug assert(!isBuild);
        foreach_reverse(l; 0..level-1)
        {
            foreach(i; 0..tree[l].length)
            {
                tree[l][i] = F(tree[l+1][i*2],tree[l+1][i*2+1]);
            }
        }
        debug isBuild = true;
    }

    void set(long index, T value){
        debug assert(!isBuild);
        size_t idx = cast(size_t)index;
        tree[$-1][idx] = value;
    }

    void update(long index, T value){
        debug assert(isBuild);
        size_t idx = cast(size_t)index;
        tree[$-1][idx] = value;
        foreach_reverse(l; 0..level-1)
        {
            idx /= 2;
            tree[l][idx] = F(tree[l+1][idx*2],tree[l+1][idx*2+1]);
        }
    }

    //all
    T get()
    {
        debug assert(isBuild);
        return tree[0][0];
    }
    //(s,t]
    T get(long s, long t)
    {
        debug assert(isBuild);
        return get(s,t,0);
    }

    private T get(long s, long t, long l)
    // in(0<=s&&t<=N&&s<=t)
    {
        if(s==t)return UNIT;

        auto c = N/(2^^l);
        auto left = (s+c-1)/c;
        auto right = t/c;

        if(left>right) return get(s,t,l+1);

        T res = UNIT;
        res = F(res, get(s, left*c, l+1));
        if(left<right)
            res = F(res, tree[l][left]);
        res = F(res, get(right*c, t, l+1));
        return res;
    }

    string toString(){
        debug println("isBuild: ", isBuild);
        string res;
        foreach(arr;tree)
        {
            foreach(elem; arr)
            {
                string elemStr = elem.to!string;

                static if(is(typeof(elem.isInf)))
                {
                    if(elem.isInf)
                    {
                        elemStr = "*";
                    }
                }
                res ~= elemStr ~ ' ';
            }
            res ~= '\n';
        }
        return res;
    }
}

unittest{
    assert(is(SegTree!(long, 0L, max)));
    assert(is(SegTree!(Tuple!(long,long), tuple(1L,0L), (a,b)=>tuple(a[0]*b[0],a[1]+b[1]))));
    assert(is(SegTree!(Tuple!(long,long), tuple(1L,0L), "tuple(a[0]*b[0],a[1]+b[1])")));
    assert(!is(SegTree!(long, 0L, "a~b")));
    assert(!is(SegTree!(long, 0L, ()=>10)));
    assert(!is(SegTree!(long, "unit", max)));

    assert(is(SegTree!(long, 0L)));
    assert(is(SegTree!(Tuple!(long, string), tuple(1L, "as"))));
    assert(!is(SegTree!(Tuple!(long, string), tuple(1L, 3L))));
}
unittest{
    auto tree = SegTree!(long, 0L, "a+b")(iota(1, 101L).array);
    assert(tree.get(0,1)==1);
    assert(tree.get(50,51)==51);
    assert(tree.get(99,100)==100);
    assert(tree.get(0,100)==5050);
    assert(tree.get(3,98)==5050-(1+2+3)-(99+100));
    assert(tree.get(3,98)==tree.get(0,100)-tree.get(0,3)-tree.get(98,100));
    assert(tree.get(50,80)==tree.get(50,60)+tree.get(60,70)+tree.get(70,80));
    assert(tree.get(1,4)==2+3+4);
    assert(tree.get(0,32)==tree.get(0,24)+tree.get(24,34)-tree.get(32,34));
    assert(tree.get(16,32)==tree.get(0,32)-tree.get(0,13)-tree.get(13,16));

    assert(tree.get()==tree.get(0,100));
}
unittest{
    struct Data{
        long x, y;
    }

    auto tree = SegTree!(Data, Data(0,INF), (a,b)=>Data(a.x+b.x,min(a.y,b.y)))([Data(1,2),Data(2,3),Data(3,4),Data(4,5)]);

    assert(tree.get(1,3)==Data(5,3));

    tree.update(2, Data(100,0));
    assert(tree.get(1,4)==Data(106,0));

    tree.update(1, Data(1,INF));
    tree.update(2, Data(1,INF));
    tree.update(3, Data(2,INF));
    assert(tree.get(1,4)==Data(4,INF));
    assert(tree.get(0,4)==Data(5,2));
}


enum INF = long.max/5;
enum MOD = 10^^9+7L;

bool isInf(long v) pure
{
    return v>=INF/5;
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
    T init;
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
        this.init = init;
        auto arr = new T[w*h];
        arr[] = init;
        this(arr, w, h, w);
    }

    void setRow(size_t y, T value)
    {
        foreach(x; 0..width)
        {
            this[x, y] = value;
        }
    }
    void setRow(InputRange)(size_t y, InputRange range)
    if(isInputRange!InputRange && is(typeof(T.init=range.front)))
    {
        foreach(x; 0..width)
        {
            assert(!range.empty);
            this[x, y] = range.front;
            range.popFront;
        }
    }

    void setCol(InputRange)(size_t x, InputRange range)
    if(isInputRange!InputRange && is(typeof(T.init=range.front)))
    {
        foreach(y; 0..height)
        {
            assert(!range.empty);
            this[x, y] = range.front;
            range.popFront;
        }
    }

    Grid!T copy(){
        if(width == stride){
            return Grid!T(grid.dup, width, height, stride);
        }

        auto res = Grid!T(width, height);
        foreach(y;0..height)
        foreach(x;0..width)
        {
            res[x, y] = this[x, y];
        }
        return res;
    }

    ref T opIndex(size_t x, size_t y)
    {
        return grid[x+stride*y];
    }
    ref T opIndex(E)(E e)
        if(
            isIntegral!(typeof(e.x)) &&
            isIntegral!(typeof(e.y)))
    {
        return this[e.x, e.y];
    }

    Grid!T opIndex(size_t[2] r1, size_t[2] r2)
    {
        auto startOffset = r1[0] + r2[0]*stride;
        auto endOffset = r1[1] + (r2[1] - 1)*stride;

        auto resGrid = grid[startOffset .. endOffset];
        auto resStride = stride;
        auto resWidth = r1[1] - r1[0];
        auto resHeight = r2[1] - r2[0];
        return Grid!T(resGrid, resWidth, resHeight, resStride);
    }
    
    Grid!T opIndex(size_t[2] r1, size_t j) { return opIndex(r1, [j, j+1]); }
    Grid!T opIndex(size_t i, size_t[2] r2) { return opIndex([i, i+1], r2); }

    size_t[2] opSlice(size_t dim)(size_t start, size_t end)
    if (dim == 0 || dim == 1)
    // in { assert(start >= 0 && end <= this.opDollar!dim); }
    body{
        return [start, end];
    }

    size_t opDollar(size_t dim : 0)() const { return width; }
    size_t opDollar(size_t dim : 1)() const { return height; }

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

    @disable this();
    this(long n){
        arr.length = cast(size_t)n;
        arr[] = -1;
    }

    void merge(long a, long b)
    {
        if(same(a,b)) return;
        arr[root(a)] = root(b);
    }

    bool same(long a, long b)
    {
        return root(a)==root(b);
    }

    private size_t root(long a)
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
    debug stderr.write(C.termStr, t, TermColor.Default.termStr);
}
void printf(TermColor C = TermColor.Gray, T...)(T t)
{
    debug stderr.write(C.termStr);
    debug stderr.writef(t);
    debug stderr.write(TermColor.Default.termStr);
}
void println(TermColor C = TermColor.Gray, T...)(T t)
{
    debug stderr.writeln(C.termStr, t, TermColor.Default.termStr);
}
void printfln(TermColor C = TermColor.Gray, T...)(T t)
{
    debug stderr.write(C.termStr);
    debug stderr.writefln(t);
    debug stderr.write(TermColor.Default.termStr);
}

// debug{
//     void write(T...)(T t)
//     {
//         stdout.write(TermColor.Blue.termStr, t, TermColor.Default.termStr);
//     }
//     void writeln(T...)(T t)
//     {
//         stdout.writeln(TermColor.Blue.termStr, t, TermColor.Default.termStr);
//     }
//     void writefln(T...)(T t)
//     {
//         stdout.writefln(TermColor.Blue.termStr, t, TermColor.Default.termStr);
//     }
// }

T[] scanArray(T = long)()
{
    return readln.split.to!(T[]);
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
T scanElem(T = long)()
{
    char[] res;
    int c = ' ';
    while (isWhite(c) && c != -1)
    {
        c = getchar;
    }
    while (!isWhite(c) && c != -1)
    {
        res ~= cast(char) c;
        c = getchar;
    }
    return res.strip.to!T;
}

dchar[] scanString(){
    return scanElem!(dchar[]).array;
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
