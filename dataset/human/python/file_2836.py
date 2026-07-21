import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv, std.math,
    std.functional, std.numeric, std.range, std.stdio, std.string, std.random,
    std.typecons, std.container, std.format;

// dfmt off
T lread(T = long)(){return readln.chomp.to!T();}
T[] lreads(T = long)(long n){return generate(()=>readln.chomp.to!T()).take(n).array();}
T[] aryread(T = long)(){return readln.split.to!(T[])();}
void scan(TList...)(ref TList Args){auto line = readln.split();
foreach (i, T; TList){T val = line[i].to!(T);Args[i] = val;}}
alias sread = () => readln.chomp();enum MOD = 10 ^^ 9 + 7;
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);
// dfmt on

void main()
{
    long N = lread();
    auto f = factorize(N);
    long ans;
    foreach (key, val; f)
    {
        // writeln(key, " ", val);
        long i = 1;
        while (i * (i + 1) <= val * 2)
            i++;
        ans += i - 1;
    }
    writeln(ans);
}
/// 素因数分解
long[long] factorize(long x)
{
    assert(0 < x, "x is negative");
    long[long] ps;
    while ((x & 1) == 0)
    {
        x /= 2;
        ps[2] = (2 in ps) ? ps[2] + 1 : 1;
    }
    for (long i = 3; i * i <= x; i += 2)
        while (x % i == 0)
        {
            x /= i;
            ps[i] = (i in ps) ? ps[i] + 1 : 1;
        }
    if (x != 1)
        ps[x] = (x in ps) ? ps[x] + 1 : 1;
    return ps;
}
