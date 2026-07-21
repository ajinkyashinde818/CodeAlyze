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
    auto xy = reads!string;

    auto x = xy[0], y = xy[1];
    if (x == y) writeln('=');
    else if (x < y) writeln('<');
    else writeln('>');
}
