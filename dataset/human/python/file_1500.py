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

bool calc(string[] a, string[] b) {
    int n = cast(int) a.length;
    int m = cast(int) b.length;

    for (int i = 0; i < n; i++) {
        if (i + m > n) break;

        for (int j = 0; j < n; j++) {
            if (j + m > n) break;

            bool ok = true;
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < m; c++) {
                    if (a[i + r][j + c] != b[r][c]) {
                        ok = false;
                    }
                }
            }
            if (ok) return true;
        }
    }

    return false;
}

void main() {
    auto nm = readints;
    int n = nm[0], m = nm[1];

    string[] a;
    for (int i = 0; i < n; i++) {
        a ~= read!string;
    }

    string[] b;
    for (int i = 0; i < m; i++) {
        b ~= read!string;
    }

    writeln(calc(a, b) ? "Yes" : "No");
}
