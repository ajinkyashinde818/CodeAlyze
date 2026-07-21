import core.bitop, std.algorithm, std.ascii, std.bigint, std.conv, std.math,
    std.functional, std.numeric, std.range, std.stdio, std.string, std.random,
    std.typecons, std.container, std.format;

// dfmt off
T lread(T = long)(){return readln.chomp.to!T();}
T[] aryread(T = long)(){return readln.split.to!(T[])();}
void scan(TList...)(ref TList Args){auto line = readln.split();
foreach (i, T; TList){T val = line[i].to!(T);Args[i] = val;}}
alias sread = () => readln.chomp();enum MOD = 10 ^^ 9 + 7;
alias PQueue = BinaryHeap!(Array!long, "a<b");
// dfmt on

void main()
{
    auto S = sread();
    writeln(S[0 .. $ - "fastival".length]);
}
