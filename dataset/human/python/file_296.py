import std.stdio, std.array, std.string, std.conv, std.algorithm;
import std.typecons, std.range, std.random, std.math, std.container;
import std.numeric, std.bigint, core.bitop;

void main() {
    auto N = readln.chomp.to!int;
    auto A = readln.split.map!(to!long).array;

    long ans = A.map!(a => abs(a)).sum;

    if (A.map!(a => a < 0).sum % 2 == 1) {
        ans -= A.map!(a => abs(a)).reduce!min * 2;
    } 

    ans.writeln;
}
