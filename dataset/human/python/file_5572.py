import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

int readint() {
    return readln.chomp.to!int;
}

int[] readints() {
    return readln.split.map!(to!int).array;
}

int calc(string s) {
    int ans = 0;
    int lo = 0;
    int hi = cast(int) s.length - 1;
    while (lo < hi) {
        if (s[lo] == s[hi]) {
            lo++;
            hi--;
        }
        else if (s[lo] == 'x') {
            lo++;
            ans++;
        }
        else if (s[hi] == 'x') {
            hi--;
            ans++;
        }
        else {
            return -1;
        }
    }
    return ans;
}

void main() {
    auto s = readln.chomp;
    writeln(calc(s));
}
