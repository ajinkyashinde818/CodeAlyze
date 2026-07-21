import std;
import core.bitop;

ulong MAX = 100_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "x", long, "g");
alias PQueue(T, alias less = "a>b") = BinaryHeap!(Array!T, less);

void main()
{
    auto s = sread();
    auto t = sread();
    writeln(sort!"a<b"(cast(ubyte[]) s).array() < sort!"a>b"(cast(ubyte[]) t).array() ? "Yes" : "No");
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
