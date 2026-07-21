import std;

alias sread = () => readln.chomp();
alias lread = () => readln.chomp.to!long();
alias aryread(T = long) = () => readln.split.to!(T[]);
//aryread!string();
//auto PS = new Tuple!(long,string)[](M);
//x[]=1;でlong[]全要素1に初期化
void main()
{
    auto n = lread();
    auto a = aryread();
    long sum_a = a.sum();
    // writeln(sum_a);
    auto s = new long[](n + 1);
    foreach (i; 0 .. n)
    {
        s[i + 1] = s[i] + a[i];
    }
    // writeln(s);
    long ans = long.max;
    long tmp;
    foreach (i; 1 .. (s.length) - 1)
    {
        // writeln(s[i], ":", sum_a - s[i]);
        tmp = abs(s[i] - (sum_a - s[i]));
        ans = min(ans, tmp);
    }
    writeln(ans);
}

void scan(L...)(ref L A)
{
    auto l = readln.split;
    foreach (i, T; L)
    {
        A[i] = l[i].to!T;
    }
}

void arywrite(T)(T a)
{
    a.map!text.join(' ').writeln;
}
