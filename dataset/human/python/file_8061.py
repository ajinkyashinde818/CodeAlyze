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

int calc(int k, int s) {
    int ans = 0;
    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
            int z = s - (x + y);
            if (z < 0) break;

            if (z <= k) ans++;
        }
    }
    return ans;
}

void main() {
    auto ks = readints;
    int k = ks[0], s = ks[1];
    writeln(calc(k, s));
}
