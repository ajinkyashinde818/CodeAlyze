import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv,
    std.functional, std.math, std.numeric, std.range, std.stdio, std.string,
    std.random, std.typecons, std.container;

ulong MAX = 1_000_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "a", long, "b");
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);

void main()
{
    long r, g, b, n;
    scan(r, g, b, n);
    long cnt;
    foreach (i; iota(n / r + 1))
    {
        foreach (j; iota(n / g + 1))
        {
            auto k = n - (i * r) - (j * g);
            if (k >= 0 && k % b == 0)
            {
                // writefln("i is %s, j is %s, k is %s", i, j, k);
                cnt++;
            }
        }
    }
    cnt.writeln();
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
