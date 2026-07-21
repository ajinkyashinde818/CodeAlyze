import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, core.bitop;

enum inf3 = 1_001_001_001;
enum inf6 = 1_001_001_001_001_001_001L;
enum mod = 1_000_000_007L;


enum L = 2001;

void main() {
    int n;
    scan(n);
    auto s = readln.chomp;

    if (s[0] != 'B' || s[2*n - 1] != 'B') {
        writeln(0);
        return;
    }

    auto b = new int[](2*n);
    foreach (i ; 0 .. 2*n) {
        if (s[i] == 'B') b[i] = 1;
        else b[i] = 0;
    }

    auto a = new int[](2*n);

    long ans = 1;
    long cnt;

    foreach (i ; 0 .. 2*n) {
        if ((cnt & 1) ^ b[i]) {
            cnt++;
        }
        else {
            ans *= cnt;
            ans %= mod;
            cnt--;
        }
    }

    if (cnt > 0) {
        writeln(0);
        return;
    }

    foreach (i ; 1 .. n + 1) {
        ans *= i;
        ans %= mod;
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
