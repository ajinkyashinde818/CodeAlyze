import std;
import core.bitop;

ulong MAX = 100_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "index", long, "num");
alias PQueue(T, alias less = "a>b") = BinaryHeap!(Array!T, less);

void main()
{
    long n, m;
    scan(n, m);
    auto a = new string[](n);
    auto b = new string[](m);
    foreach (ref e; a)
        e = sread();
    foreach (ref e; b)
        e = sread();

    bool includes(long x, long y)
    {
        bool ret = true;
        foreach (i; iota(m))
        {
            ret &= (a[x + i][y .. y + m] == b[i]);
        }
        return ret;
    }

    foreach (i; iota(n - m + 1))
    {
        foreach (j; iota(n - m + 1))
        {
            if (includes(i, j))
            {
                writeln("Yes");
                return;
            }
        }
    }
    writeln("No");
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
