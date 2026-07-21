import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, core.bitop;

enum inf3 = 1_001_001_001;
enum inf6 = 1_001_001_001_001_001_001L;
enum mod = 1_000_000_007L;


void main() {
    int n;
    scan(n);
    auto a = readln.split.to!(long[]);

    auto asum = a.sum();
    auto tn = 1L * n * (n + 1) / 2;

    if (asum % tn) {
        writeln("NO");
        return;
    }

    auto K = asum / tn;

    auto d = new long[](n);
    foreach (i ; 0 .. n) {
        d[i] = a[(i + 1) % n] - a[i];
    }

    d[] -= K;

    debug {
        writeln(d);
    }

    long cnt;

    foreach (i ; 0 .. n) {
        if (d[i] > 0 && d[i] % n) {
            writeln("NO");
            return;
        }
        cnt += abs(d[i]) / n;
    }

    writeln(cnt == K ? "YES" : "NO");
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
