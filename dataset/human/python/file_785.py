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
    long N, R;
    scan(N, R);
    writeln((10 <= N) ? R : R + 100 * (10 - N));
}
