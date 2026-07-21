import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv,
    std.functional, std.math, std.numeric, std.range, std.stdio, std.string,
    std.random, std.typecons, std.container;

ulong MAX = 1_000_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "p", long, "dist");
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);

void main()
{
    auto s = sread();
    long iter = s.length;
    auto dream = "dream", dreamer = "dreamer";
    auto erase = "erase", eraser = "eraser";
    while (iter > 0)
    {
        if(s[max(0, iter - cast(long) dream.length) .. iter] == dream)
            iter -= dream.length;
        else if(s[max(0, iter - cast(long) dreamer.length) .. iter] == dreamer)
            iter -= dreamer.length;
        else if(s[max(0, iter - cast(long) erase.length) .. iter] == erase)
            iter -= erase.length;
        else if(s[max(0, iter - cast(long) eraser.length) .. iter] == eraser)
            iter -= eraser.length;
        else
            break;
    }
    if(iter)
        writeln("NO");
    else
        writeln("YES");
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
