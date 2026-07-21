import std.stdio, std.string, std.range, std.conv, std.array, std.algorithm, std.math, std.typecons;

void main() {

    auto N = readln.chomp.to!long;

    auto a = readln.split.to!(long[]);

    foreach (i; 1..N) {
        a[i] += a[i-1];
    }

    auto s = a.back;


    a[0..$-1].map!(a => abs(a * 2 - s)).reduce!min.writeln;
}
