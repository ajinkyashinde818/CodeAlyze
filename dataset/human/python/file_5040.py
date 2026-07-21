import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.stdio;
import std.string;
import std.range;

int readint() {
    return readln.chomp.to!int;
}

int[] readints() {
    return readln.split.map!(to!int).array;
}

void main() {
    auto nm = readints();
    int n = nm[0], m = nm[1];

    auto xs = new bool[](n + 1); // 1 から i へ定期便があるか
    auto ys = new bool[](n + 1); // n から i へ定期便があるか
    for (int i = 0; i < m; i++) {
        auto ab = readints();
        int a = ab[0], b = ab[1];
        if (a > b)
            swap(a, b);

        if (a == 1)
            xs[b] = true;
        if (b == n)
            ys[a] = true;
    }

    bool found = false;
    for (int i = 2; i < n; i++) {
        if (xs[i] && ys[i]) {
            found = true;
            break;
        }
    }
    writeln(found ? "POSSIBLE" : "IMPOSSIBLE");
}
