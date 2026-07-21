import std.stdio, std.string, std.conv, std.range;
import std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, std.random, core.bitop;

enum inf = 1_001_001_001;
enum infl = 1_001_001_001_001_001_001L;


void main() {
    int N, K, S;
    scan(N, K, S);

    auto a = new int[](N);

    if (S == 1) {
        foreach (i ; 0 .. N) {
            a[i] = (i < K ? 1 : 2);
        }
    }
    else if (S == 2) {
        foreach (i ; 0 .. N) {
            a[i] = (i < K ? 2 : 3);
        }
    }
    else {
        foreach (i ; 0 .. N) {
            a[i] = (i < K ? S : S - 1);
        }
    }

    writefln("%(%s %)", a);
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
