import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, core.bitop;

enum inf = 1_001_001_001;
enum inf6 = 1_001_001_001_001_001_001L;
enum mod = 1_000_000_007L;


void main() {
    int N;
    scan(N);
    auto A = readln.split.to!(int[]);
    auto B = readln.split.to!(int[]);
    auto C = readln.split.to!(int[]);

    auto ans = B.sum();
    foreach (i ; 0 .. N - 1) {
        if (A[i] == N) continue;
        ans += (A[i] + 1 == A[i + 1]) * C[A[i] - 1];
    }
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
