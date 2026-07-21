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

void main() {
    auto s = readln.chomp;

    auto t = s.array;
    t.sort();
    writeln(t == "abc" ? "Yes" : "No");
}
