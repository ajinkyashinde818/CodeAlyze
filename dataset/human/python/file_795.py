import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv,
    std.functional, std.math, std.numeric, std.range, std.stdio, std.string,
    std.random, std.typecons, std.container;

ulong MAX = 1_000_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "begin", long, "end");
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);

void main()
{
    long n, r;
    scan(n, r);
    if(n < 10)
        writeln(r + 100 * (10 - n));
    else
        writeln(r);
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
