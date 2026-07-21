import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, core.bitop;

void main() {
    int d, g;
    scan(d, g);

    auto p = new int[](d);
    auto c = new int[](d);

    foreach (i ; 0 .. d) {
        scan(p[i], c[i]);
    }

    int ans = 1<<30;

    foreach (s ; 0 .. (1<<d)) {
        int score;
        int toita;

        foreach (i ; 0 .. d) {
            if (s & (1<<i)) {
                score += 100*(i+1)*p[i];
                score += c[i];
                toita += p[i];
            }
        }

        foreach_reverse (i ; 0 .. d) {
            if (score >= g) {
                break;
            }
            if (s & (1<<i)) {
                continue;
            }
            int t = min(p[i], (g - score + (i+1)*100 - 1) / ((i+1)*100));
            score += t*(i+1)*100;
            toita += t;
        }

        ans = min(ans, toita);
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
