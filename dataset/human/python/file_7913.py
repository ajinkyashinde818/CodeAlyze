import std.stdio;
import std.conv;
import std.string;
import std.algorithm;
import std.range;
import std.functional;
import std.math;
import core.bitop;

void main()
{
    /// ABC089_D
    string s = readln.chomp;
    writeln((s.canFind('a') && s.canFind('b') && s.canFind('c')) ? "Yes" : "No");
}
