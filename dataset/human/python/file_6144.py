import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

T read(T)() { return readln.chomp.to!T; }
T[] reads(T)() { return readln.split.to!(T[]); }
alias readint = read!int;
alias readints = reads!int;

long calc(int a, int b, int c) {
    long ans = 0;

    // 毒入り(美味しい) -> 解毒剤(美味しい)の順に食べる
    int x = min(b, c);
    ans += x * 2;
    b -= x;
    c -= x;

    // 毒入り(美味しい) -> 解毒剤(美味しくない)の順に食べる
    x = min(a, c);
    ans += x;
    a -= x;
    c -= x;

    // 毒入り(美味しい)が余っているなら 1 枚だけ食べる
    if (c > 0) ans++;

    // 余りの解毒剤(美味しい)を食べる
    ans += b;
    return ans;
}

long calc2(int a, int b, int c) {
    int d = min(c, a + b + 1);
    return b + d;
}

void main() {
    auto abc = readints;
    int a = abc[0], b = abc[1], c = abc[2];
    writeln(calc2(a, b, c));
}
