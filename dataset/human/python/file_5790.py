import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv,
    std.functional, std.math, std.numeric, std.range, std.stdio, std.string,
    std.random, std.typecons, std.container;

ulong MAX = 1_000_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "l    ", long, "r");
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);

void main()
{
    auto n = lread();
    auto a = aryread();
    auto b = aryread();
    auto c = aryread();
    long s = b.sum();
    foreach (i; iota(n - 1))
    {
        if(a[i + 1] - a[i] == 1)
            s += c[a[i] - 1];
    }
    s.writeln();
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
