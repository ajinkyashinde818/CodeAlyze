import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;
 
void main() {
    auto s = readln.split;
    char c = (s[0] == s[1]) ? '=' : (s[0] < s[1] ? '<' : '>');
    writefln("%s", c);
}
