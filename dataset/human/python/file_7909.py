import std.stdio, std.algorithm, std.string, std.conv, std.array, std.range, std.math;

void main() {
    string s = readln.chomp;
    bool can = 1;
    foreach(c; "abc") can &= (count(s, c) == 1);
    writeln(can ? "Yes" : "No");
}
