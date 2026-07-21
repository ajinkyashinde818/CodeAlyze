import std.stdio;
import std.string;
import std.conv;
import std.array;
import std.algorithm;

void main() {
    auto input = readln.split.map!(to!int);
    int K = input[0], S = input[1];

    int ans = 0;

    foreach (x; 0 .. K + 1) {
        foreach (y; 0 .. K + 1) {
            int z = S - (x + y);
            if (z >= 0 && K >= z) {
                ans++;
            }
        }
    }

    writeln(ans);
}
