import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, core.bitop;

enum inf3 = 1_001_001_001;
enum inf6 = 1_001_001_001_001_001_001L;
enum mod = 1_000_000_007L;


void main() {
    string s;
    scan(s);
    int x, y;
    scan(x, y);

    auto t = s.dup;
    int xs;
    while (!t.empty && t.front == 'F') {
        xs++;
        t.popFront();
    }

    debug {
        writeln("xs:", xs);
        writeln("t:", t);
    }

    auto xa = new int[][](2, 0);
    int mode;

    foreach (i ; 0 .. t.length) {
        if (t[i] == 'T') {
            mode ^= 1;
            xa[mode] ~= 0;
        }
        else {
            xa[mode].back += 1;
        }
    }

    debug {
        writeln(xa[0]);
        writeln(xa[1]);
    }

    xa[0] = xa[0].filter!"a > 0".array;
    xa[1] = xa[1].filter!"a > 0".array;

    auto ans = solve(xa[0], x, xs) && solve(xa[1], y, 0);

    writeln(ans ? "Yes" : "No");
}


bool solve(int[] a, int x, int s) {
    auto m = a.length.to!int;
    int zero = 8000;
    auto dp = new bool[][](m + 1, 2*zero + 1);
    dp[0][zero + s] = true;

    foreach (i ; 0 .. m) {
        foreach (j ; 0 .. 2*zero + 1) {
            if (j - a[i] >= 0) {
                dp[i + 1][j - a[i]] |= dp[i][j];
            }
            if (j + a[i] <= 2*zero) {
                dp[i + 1][j + a[i]] |= dp[i][j];
            }
        }

        debug {
            writefln("%(%b%)", dp[i + 1][zero .. zero + 20]);
        }
    }

    return dp[m][zero + x];
}





void scan(T...)(ref T args) {
    import std.stdio : readln;
    import std.algorithm : splitter;
    import std.conv : to;
    import std.range.primitives;

    auto line = readln().splitter();
    foreach (ref arg; args) {
        arg = line.front.to!(typeof(arg));
        line.popFront();
    }
    assert(line.empty);
}

void fillAll(R, T)(ref R arr, T value) {
    static if (is(typeof(arr[] = value))) {
        arr[] = value;
    }
    else {
        foreach (ref e; arr) {
            fillAll(e, value);
        }
    }
}
