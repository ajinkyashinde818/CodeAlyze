import std.stdio, std.string, std.algorithm, std.array, std.range, std.conv,
    std.typecons, std.math, std.container, std.format;

void main(string[] args)
{
    long n;
    readf("%d\n", &n);

    if (n % 2 == 1)
    {
        writeln(0);
    }
    else
    {
        long count = 0;
        n /= 2;
        for (long i = 5; n / i >= 1; i *= 5)
        {
            count += n / i;
        }
        writeln(count);
    }

}
