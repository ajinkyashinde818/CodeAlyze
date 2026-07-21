import std.stdio, std.string, std.conv, std.range;
import std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, std.random, core.bitop;

enum inf = 1_001_001_001;
enum infl = 1_001_001_001_001_001_001L;
enum mod = 1_000_000_007L;

void main() {
    auto N = readln.chomp.map!(i => (i - '0').to!int).retro.array;
    N ~= 0;

    auto L = N.length.to!int;

    auto dp = new int[][](L + 1, 2);
    fillAll(dp, inf);
    dp[0][0] = 0;

    foreach (i ; 0 .. L) {
        foreach (j ; 0 .. 2) {
            foreach (d ; 0 .. 10) {
                int x = N[i] + j;
                if (d < x) {
                    chmin(dp[i + 1][1], dp[i][j] + d + 10 + d - x);
                }
                else {
                    chmin(dp[i + 1][0], dp[i][j] + d + d - x);
                }
            }
        }
    }

    auto ans = dp[L][0];
    writeln(ans);
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

bool chmin(T, U...)(ref T x, U args) {
    bool isChanged;

    foreach (arg; args) {
        if (x > arg) {
            x = arg;
            isChanged = true;
        }
    }

    return isChanged;
}

bool chmax(T, U...)(ref T x, U args) {
    bool isChanged;

    foreach (arg; args) {
        if (x < arg) {
            x = arg;
            isChanged = true;
        }
    }

    return isChanged;
}
