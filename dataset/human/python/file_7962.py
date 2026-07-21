import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons;
import std.math, std.numeric;


void main() {
    int n; scan(n);
    auto a = readln.split.to!(int[]);
    auto b = readln.split.to!(int[]);

    auto bk = new int[][][](30, 2, 0);

    foreach (i ; 0 .. 30) {
        foreach (bj ; b) {
            int bl = bj & ((1<<i) - 1);
            bk[i][(bj >> i) & 1] ~= bl;
        }

        bk[i][0].sort();
        bk[i][1].sort();
    }

    int ans;

    foreach (k ; 0 .. 30) {
        long cnt;

        foreach (ai ; a) {
            int al = ai & ((1<<k) - 1);

            int sw = (ai >> k) & 1;
            int ub = (1 << k) - al;
            cnt += bk[k][1-sw].assumeSorted.lowerBound(ub).length.to!int;
            cnt += bk[k][sw].length.to!int - bk[k][sw].assumeSorted.lowerBound(ub).length.to!int;
        }

        ans ^= ((cnt & 1) << k);
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
