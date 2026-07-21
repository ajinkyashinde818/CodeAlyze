import std.stdio;
import std.range;
import std.array;
import std.functional;
import std.algorithm;
import std.conv;
import std.container;
import std.math;
import std.numeric;
import std.string;

void main() {
    int N; readf("%d\n", &N);
    int[] d = new int[100003];
    int[] r = new int[100003];
    foreach (i; 0 .. N) {
        int a, b; readf("%d %d\n", &a, &b);
        d[a]++;
        d[b + 1]--;
    }
    int c = 0;
    foreach (i; 2 .. 100003) {
        c += d[i];
        r[i] = c;
    }
    int ans = 0;
    foreach (i; 2 .. 100003) {
        if (r[i] >= i - 1) {
            ans = i - 1;
        }
    }
    ans.writeln;
}
