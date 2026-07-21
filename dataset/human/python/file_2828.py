import std;

ulong MAX = 100_100, MOD = 1_000_000_007, INF = 1_000_000_000_000;
alias sread = () => readln.chomp();
alias lread(T = long) = () => readln.chomp.to!(T);
alias aryread(T = long) = () => readln.split.to!(T[]);
alias Pair = Tuple!(long, "base", long, "cnt");
alias PQueue(T, alias less = "a>b") = BinaryHeap!(Array!T, less);

void main()
{
    auto N = lread();
    auto p = N.make_primeF_pairs();
    long bseach(long t)
    {
        long ok = -1, ng = t + 1;
        while (abs(ok - ng) > 1)
        {
            auto mid = (ok + ng) / 2;
            if (mid * (mid + 1) / 2 <= t)
                ok = mid;
            else
                ng = mid;
        }
        // ok.writeln();
        return ok;
    }

    long ans;
    p.each!(x => ans += bseach(x.cnt));
    ans.writeln();
}

auto factors(long N)
{
    long iter = 1;
    long[] ret;
    while (true)
    {
        if (iter ^^ 2 > N)
            break;
        if (!(N % iter))
            ret ~= only(iter, N / iter).array();

        iter++;
    }
    return ret;
}

auto primeFactors(long N)
{
    auto fs = N.factors();
    auto ret = fs.filter!(x => x != 1 && x.factors.length == 2).array();
    return ret;
}

auto make_primeF_pairs(long N)
{
    auto pfps = N.primeFactors();
    Pair[] ret;
    foreach (e; pfps)
    {
        long cnt;
        while (!(N % e))
        {
            cnt++;
            N /= e;
        }
        ret ~= Pair(e, cnt);
    }
    return ret;
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
