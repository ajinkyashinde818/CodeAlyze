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
    readint;
    auto a = readints;
    auto b = readints;
    auto c = readints;

    int ans = 0;
    for (int i = 0; i < a.length; i++) {
        ans += b[a[i] - 1];

        if (i + 1 < a.length) {
            int x = a[i]; // 食べた料理
            int y = a[i + 1]; // 次に食べる料理
            if (y == x + 1) {
                ans += c[a[i] - 1];
            }
        }
    }
    writeln(ans);
}
