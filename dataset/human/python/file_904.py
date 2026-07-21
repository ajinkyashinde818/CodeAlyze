import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.math;

void main() {
    int n;
    long c;
    scan(n, c);
    auto x = new long[](n);
    auto v = new long[](n);
    iota(n).each!(i => scan(x[i], v[i]));

    long ans;
    ans = max(straight(n, c, x, v), straight(n, c, x.map!(xi => c - xi).retro.array, v.retro.array));
    debug {
        writeln(straight(n, c, x, v), ' ', straight(n, c, x.map!(xi => c - xi).retro.array, v.retro.array));
    }
    ans = max(ans, turn(n, c, x, v), turn(n, c, x.map!(xi => c - xi).retro.array, v.retro.array));
    debug {
        writeln(turn(n, c, x, v), ' ',  turn(n, c, x.map!(xi => c - xi).retro.array, v.retro.array));
    }


    writeln(ans);
}

long turn(int n, long c, long[] x, long[] v) {
    auto pm = new long[](n + 1);

    long s;
    foreach (i ; 1 .. n + 1) {
        s += v[i-1];
        pm[i] = max(pm[i-1], s - 2*x[i-1]);
    }

    long ans = pm[n];
    s = 0;
    foreach (i ; 1 .. n + 1) {
        s += v[n - i];
        ans = max(ans, pm[n - i] + s - (c - x[n - i]));
    }

    return ans;
}

long straight(int n, long c, long[] x, long[] v) {
    long ans;
    long cal;

    foreach (i ; 0 .. n) {
        cal += v[i];
        ans = max(ans, cal - x[i]);
    }

    return ans;
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
