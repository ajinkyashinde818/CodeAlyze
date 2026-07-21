import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, core.bitop;


void main() {
    int n;
    scan(n);

    int k = 2;
    while (k*(k-1)/2 < n) {
        k++;
    }

    if (n != k*(k-1)/2) {
        writeln("No");
        return;
    }

    writeln("Yes");
    writeln(k);

    auto ans = new int[][](k, 0);

    int num = 1;

    foreach (i ; 0 .. k) {
        foreach (j ; i+1 .. k) {
            ans[i] ~= num;
            ans[j] ~= num;
            num++;
        }
    }

    foreach (ansi ; ans) {
        writefln("%d %(%s %)", k - 1, ansi);
    }
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
