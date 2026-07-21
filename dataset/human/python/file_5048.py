import std.stdio, std.string, std.range, std.conv, std.array, std.algorithm, std.math, std.typecons;

void main() {
    int N, M;
    readf("%d %d\n", &N, &M);
    bool[] first = new bool[N];
    bool[] last = new bool[N];
    foreach (i; 0..M) {
        int a, b;
        readf("%d %d\n", &a, &b);
        if (a == 1) first[b-1] = true;
        if (b == N) last[a-1] = true;
    }
    writeln(N.iota.any!(i => first[i] && last[i]) ? "POSSIBLE" : "IMPOSSIBLE");
}
