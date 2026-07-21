import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv,
    std.functional, std.math, std.numeric, std.range, std.stdio, std.string,
    std.random, std.typecons, std.container;

ulong MAX = 100_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "a", long, "b");
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);

void main()
{
    long n, m;
    scan(n, m);
    auto from = new bool[](n);
    auto to = new bool[](n);
    foreach (_; iota(m))
    {
        long a, b;
        scan(a, b);
        if (a == 1)
            to[b - 1] = true;
        if (b == n)
            from[a - 1] = true;
    }
    long ans;
    foreach (i; iota(n))
    {
        ans |= (from[i] && to[i]);
    }
    if (ans)
        writeln("POSSIBLE");
    else
        writeln("IMPOSSIBLE");
}

void scan(TList...)(ref TList Args)
{
    auto line = readln.split();
    foreach (i, T; TList)
    {
        T val = line[i].to!(T);
        Args[i] = val;
    }
}
