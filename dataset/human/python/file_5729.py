import std.stdio;
import std.c.stdio;
import std.range;
import std.array;
import std.functional;
import std.algorithm;
import std.conv;
import std.container;
import std.math;
import std.numeric;
import std.string;
import std.c.string;
import std.regex;
import std.typecons;
 
void main() {
    int N;
    char[][] F;
    bool input() {
        scanf("%d\n", &N);
        if (N == 0) return false;
        F = new char[][N];
        foreach (i; 0 .. N) F[i] = cast(char[])(readln.chomp);
        return true;
    }
    void solve() {
        foreach (i; 1 .. N) {
            auto level = F[i].countUntil!("a != '.'");
            F[i][level - 1] = '+';
            for (long j = i - 1; j >= 0 && F[j][level - 1] == '.'; j--) {
                F[j][level - 1] = '|';
            }
        }
        foreach (i; 0 .. N) {
            foreach (ref c; F[i]) {
                if (c == '.') c = ' ';
            }
        }
        foreach (ref L; F) L.writeln;
    }
    while (input) solve;
}
