import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

T read(T)() { return readln.chomp.to!T; }
T[] reads(T)() { return readln.split.to!(T[]); }
alias readint = read!int;
alias readints = reads!int;

long calc(long[] xs) {
    long sum = xs.map!abs.sum;
    auto n = xs.count!(e => e < 0);
    if (n % 2 == 0) return sum;
    auto m = xs.map!abs.reduce!min;
    return sum - m * 2;
}

void main() {
    readint;
    auto xs = reads!long;
    writeln(calc(xs));
}
