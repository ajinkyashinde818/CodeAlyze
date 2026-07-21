import std.stdio;
import std.conv;
import std.string;
import std.algorithm;
import std.array;

void main() {
    auto tmp = readln.split.map!(s => s.chomp[0]).array;
    auto X = tmp[0];
    auto Y = tmp[1];
    writeln(X == Y ? "=" : X < Y ? "<" : ">");
}
