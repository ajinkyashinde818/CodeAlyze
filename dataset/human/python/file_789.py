import std.algorithm;
import std.array;
import std.container;
import std.conv;
import std.math;
import std.numeric;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

void scan(T...)(ref T a) {
    string[] ss = readln.split;
    foreach (i, t; T) a[i] = ss[i].to!t;
}
T read(T)() { return readln.chomp.to!T; }
T[] reads(T)() { return readln.split.to!(T[]); }
alias readint = read!int;
alias readints = reads!int;

void main() {
    int n, r; scan(n, r);
    int ans = n >= 10
        ? r
        : r + 100 * (10 - n);
    writeln(ans);
}
