import std;

alias sread = () => readln.chomp();
alias lread = () => readln.chomp.to!long();
alias aryread(T = long) = () => readln.split.to!(T[]);

void main()
{
    auto x = lread();
    if (x < 1200)
    {
        writeln("ABC");
        return;
    }
    writeln("ARC");
}

void scan(L...)(ref L A)
{
    auto l = readln.split;
    foreach (i, T; L)
    {
        A[i] = l[i].to!T;
    }
}
