import std.stdio, std.conv, std.string, std.array, std.range, std.algorithm, std.container;
import std.math, std.random, std.bigint, std.datetime, std.format;
import std.typecons, std.regex;

void main() {
    auto s = read.to!string;
    writeln(s[0..$-8]);
}

string read() {
    static string[] ss;
    while (!ss.length) ss = readln.chomp.split;
    auto res = ss[0];
    ss.popFront;
    return res;
}
