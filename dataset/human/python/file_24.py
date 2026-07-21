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

void main() {
    auto a = readints;
    int r = a[0], g = a[1], b = a[2], n = a[3];

    int ans = 0;
    for (int i = 0; i * r <= n; i++) {
        for (int j = 0; j * g <= n; j++) {
            int m = n - (i * r + j * g);
            if (m < 0) break;

            if (m % b == 0) ans++;
        }
    }
    writeln(ans);
}
