import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

int readint() {
    return readln.chomp.to!int;
}

int[] readints() {
    return readln.split.map!(to!int).array;
}

void main() {
    auto s = readln.chomp;
    auto t = s.take(s.length - 8);
    writeln(t);
}
