import std.stdio;
import std.ascii;
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
import std.random;
import std.regex;
import std.typecons;

int N; 

int parse(in string s) {
    int[char] M = [
        'm': 1000,
        'c': 100,
        'x': 10,
        'i': 1
    ];
    int ret = 0;
    int p = 1;
    foreach (c; s) {
        if (isDigit(c)) {
            p = cast(int)(c - '0');
        } else {
            ret += p * M[c];
            p = 1;
        }
    }
    return ret;
}

string to_s(int n) {
    int[] x = [0, 0, 0, 0];
    x[0] = n / 1000; n %= 1000;
    x[1] = n / 100;  n %= 100;
    x[2] = n / 10;   n %= 10;
    x[3] = n;

    string p = "mcxi";

    string ret;
    foreach (i; 0 .. 4) {
        if (x[i] == 0) {
            // do nothing
        } else if (x[i] == 1) {
            ret ~= p[i];
        } else {
            ret ~= format("%d%s", x[i], p[i]);
        }
    }
    return ret;
}

void solve() {
    string s, t; readf("%s %s\n", &s, &t);
    //writeln([parse(s), parse(t)]);
    //writeln((parse(s) + parse(t)));
    writeln(to_s(parse(s) + parse(t)));
}

void main() {
    scanf("%d\n", &N);
    foreach (i; 0 .. N) {
        solve();
    }
}
