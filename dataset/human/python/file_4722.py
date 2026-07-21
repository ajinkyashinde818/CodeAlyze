import std.stdio, std.string, std.range, std.conv, std.array, std.algorithm, std.math, std.typecons;

void main() {
    auto s = sort!"a < b"(readln.chomp.to!dstring.dup).array;
    auto t = sort!"a > b"(readln.chomp.to!dstring.dup).array;
    writeln(s < t ? "Yes" : "No");
}
