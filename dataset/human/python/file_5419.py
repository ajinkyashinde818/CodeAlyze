import std.stdio, std.string, std.conv, std.bigint, std.typecons, std.algorithm, std.array, std.math, std.range;
 
void main() {
    auto N = readln.chomp.to!int;
    writeln(N / 10 == 9 || N % 10 == 9 ? "Yes" : "No");
}
