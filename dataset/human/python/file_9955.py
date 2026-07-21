import std.conv, std.stdio;
import std.algorithm, std.array, std.range, std.string;
import std.numeric;
void main()
{
    auto buf = readln.chomp.split.to!(long[]);
    (buf[0] * (buf[1] / buf[0].gcd(buf[1]))).writeln;
}
