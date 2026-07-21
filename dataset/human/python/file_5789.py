import std.stdio, std.string, std.array, std.conv;

void main() {
    int n = readln.chomp.to!int;
    int[] a = readln.chomp.split.to!(int[]);
    a[] -= 1;
    int[] b = readln.chomp.split.to!(int[]);
    int[] c = readln.chomp.split.to!(int[]);
    int prev = int.min, sum;
    foreach (x; a) {
        sum += b[x];
        if (prev == x - 1) sum += c[prev];
        prev = x;
    }
    sum.writeln;
}
