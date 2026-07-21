import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv, std.math,
    std.functional, std.numeric, std.range, std.stdio, std.string, std.random,
    std.typecons, std.container, std.format;
static import std.ascii;

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
    long D, G;
    scan(D, G);
    auto P_orig = new long[](D);
    auto C = new long[](D);
    foreach (i; 0 .. D)
        scan(P_orig[i], C[i]);

    long ans = long.max;

    foreach (comp; 0 .. (1 << D))
    {
        auto P = P_orig.dup;
        long score;
        long cnt;
        foreach (i; 0 .. D)
            if (comp & (1 << i))
            {
                cnt += P[i];
                score += P[i] * 100 * (i + 1);
                score += C[i];
                P[i] = 0;
            }
        if (G <= score)
        {
            ans = ans.min(cnt);
            continue;
        }
        foreach_reverse (i; 0 .. D)
        {
            long need = (G - score + (100 * (i + 1) - 1)) / (100 * (i + 1));
            long c = min(need, P[i]);
            // writefln("%s %s %s %s %s", comp, G - score, i, need, P[i]);
            score += c * (100 * (i + 1));
            cnt += c;
            if (G <= score)
                break;
        }
        ans = ans.min(cnt);
    }
    writeln(ans);
}
