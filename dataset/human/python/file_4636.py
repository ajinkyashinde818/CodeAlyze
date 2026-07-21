import std;

auto input()
{
    return readln().chomp();
}

alias sread = () => readln.chomp();

void main()
{
    string s = input();
    long s_len = s.length;
    //writeln(s);
    //writeln(s_len);
    writeln(s[0 .. ((s.length) - 8)]);
}

void scan(L...)(ref L A)
{
    auto l = readln.split;
    foreach (i, T; L)
    {
        A[i] = l[i].to!T;

    }
}
