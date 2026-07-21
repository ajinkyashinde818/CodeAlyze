import std.conv, std.stdio;
import std.algorithm, std.array, std.string, std.range;

void main()
{
    auto
        buf = readln.chomp.split.to!(int[]),
        k = buf[0],
        n = buf[1],
        a = readln.chomp.split.to!(int[]),
        l = a[0] + k - a[$-1];
    foreach (i, e; a[1..$])
        l = l.max(e - a[i]);
    (k - l).writeln;
}
