import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv,
    std.functional, std.math, std.numeric, std.range, std.stdio, std.string,
    std.random, std.typecons, std.container;

ulong MAX = 1_000_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Clue = Tuple!(long, "x", long, "y", long, "h");
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);

long cnt;

void main()
{
    long k, n;
    scan(k, n);
    auto a = aryread();
    auto dif = new long[](n);
    foreach(i; iota(n))
    {
        dif[i] = a[(i + 1) % n] - a[i];
        if(dif[i] < 0)
            dif[i] += k;
    }
    dif.sort();
    writeln(k - dif[$ - 1]);
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
