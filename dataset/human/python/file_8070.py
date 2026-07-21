import std.stdio, std.string, std.conv, std.algorithm, std.range;

void main() {
    auto tmp = readln.split.to!(int[]);
    auto K = tmp[0], S = tmp[1];
    iota(K+1).map!(x => max(0, min(S-x, K) - max(0, S - K - x) + 1)).sum.writeln;
}
