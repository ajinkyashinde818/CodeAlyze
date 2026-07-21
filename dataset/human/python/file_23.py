import std;

alias sread = () => readln.chomp();
alias lread = () => readln.chomp.to!long();
alias aryread(T = long) = () => readln.split.to!(T[]);
//aryread!string();
void main()
{
    long r, g, b, n;
    scan(r, g, b, n);
    // writeln(r, g, b, n);
    long cnt;
    foreach (i; 0 .. 3001)
    {
        foreach (j; 0 .. 3001)
        {
            long tmp;
            if (r * i + g * j <= n)
            {
                tmp = n - (r * i + g * j);
                if (tmp % b == 0)
                {
                    cnt += 1;
                }
            }
        }
    }
    writeln(cnt);
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
