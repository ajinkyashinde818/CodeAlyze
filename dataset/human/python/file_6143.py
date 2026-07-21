import std.stdio, std.string, std.conv, std.range;
import std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, std.random, core.bitop;

enum inf = 1_001_001_001;
enum infl = 1_001_001_001_001_001_001L;




void main() {
    long a, b, c;
    scan(a, b, c);
    auto ans = b;
    if (a + b >= c) {
        ans += c;
    }
    else {
        long t = a + b + 1;
        ans += t;
    }
    writeln(ans);
}






void scan(T...)(ref T args) {
    auto line = readln.split;
    foreach (ref arg; args) {
        arg = line.front.to!(typeof(arg));
        line.popFront;
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
    foreach (arg; args) if (x > arg) {
        x = arg;
        isChanged = true;
    }
    return isChanged;
}

bool chmax(T, U...)(ref T x, U args) {
    bool isChanged;
    foreach (arg; args) if (x < arg) {
        x = arg;
        isChanged = true;
    }
    return isChanged;
}

void yes(bool ok, string y = "Yes", string n = "No") {
    return writeln(ok ? y : n);
}
