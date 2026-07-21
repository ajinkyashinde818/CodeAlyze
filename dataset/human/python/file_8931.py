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
    auto S = sread();
    auto T = ["dreamer", "eraser", "erase", "dream"];
    long i = S.length;
    w: while (0 < i)
    {
        foreach (t; T)
        {
            // writeln(max(0, i - cast(long)t.length), " ", min(i, S.length));
            if (S[max(0, i - cast(long)t.length) .. min(i, S.length)] == t)
            {
                i -= t.length;
                continue w;
            }
        }
        writeln("NO");
        return;
    }
    writeln("YES");
}
