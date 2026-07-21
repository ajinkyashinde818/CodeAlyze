import std;

ulong MAX = 100_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "cur", long, "prev");
alias PQueue(T, alias less = "a>b") = BinaryHeap!(Array!T, less);

void main()
{
    long n, k;
    scan(n, k);
    auto next = aryread.map!(x => x - 1).array();
    long[] tele;
    auto reached = new long[](n);
    long cur;
    while (!reached[cur])
    {
        tele ~= cur;
        reached[cur] = true;
        cur = next[cur];
    }
    auto nloops = tele[0 .. tele.countUntil(cur)], loops = tele[tele.countUntil(cur) .. $];
    if (k >= nloops.length)
    {
        k -= nloops.length;
        writeln(loops[k % loops.length] + 1);
    }
    else
    {
        writeln(nloops[k] + 1);
    }
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
