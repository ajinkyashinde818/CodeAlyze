import std.conv, std.stdio;
import std.algorithm, std.array, std.range, std.string;
import std.numeric;
void main()
{
    auto n = readln.chomp.to!ulong;
    if (n & 1)
        return 0.writeln;
    n /= 2;
    ulong ret;
    while (n)
    {
        n /= 5;
        ret += n;
    }
    ret.writeln;
}
