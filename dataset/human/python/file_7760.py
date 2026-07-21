import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv, std.math,
    std.functional, std.numeric, std.range, std.stdio, std.string, std.random,
    std.typecons, std.container, std.format;
static import std.ascii;

// dfmt off
T lread(T = long)(){return readln.chomp.to!T();}
T[] aryread(T = long)(){return readln.split.to!(T[])();}
void scan(TList...)(ref TList Args){auto line = readln.split();
foreach (i, T; TList){T val = line[i].to!(T);Args[i] = val;}}
alias sread = () => readln.chomp();enum MOD = 10 ^^ 9 + 7;
alias PQueue(T, alias less = "a<b") = BinaryHeap!(Array!T, less);
// dfmt on

void main()
{
    long N, K, S;
    scan(N, K, S);
    if (N == K)
    {
        repeat(S).take(N).map!text().join(' ').writeln();
        return;
    }
    if (S == 10 ^^ 9)
    {

        repeat(S).take(K).map!text().join(' ').write();
        write(" ");
        repeat(S - 1).take(N - K).map!text().join(' ').write();
        return;
    }
    if (K == 0)
    {
        repeat(S + 1).take(N).map!text().join(' ').writeln();
        return;
    }
    repeat(S).take(K).map!text().join(' ').write();
    write(" ");
    repeat(S + 1).take(N - K).map!text().join(' ').write();
}
