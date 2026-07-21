import std.algorithm;
import std.array;
import std.ascii;
import std.container;
import std.conv;
import std.math;
import std.numeric;
import std.range;
import std.stdio;
import std.string;
import std.typecons;
void log(A...)(A arg) { stderr.writeln(arg); }
int size(T)(in T s) { return cast(int)s.length; }

void main() {
    int x = readln.chomp.to!int;
    writeln((x < 1200 ? "ABC" : "ARC"));
}
